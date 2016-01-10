#include "postgres.h"
#include "executor/spi.h"
#include "../../common/src/connection.h"
#include "../../common/src/structs.h"
#include "dijkstra_function.h"
#include "funcapi.h"
#include "utils/lsyscache.h"
#include "catalog/pg_type.h"
#if PGSQL_VERSION > 92
#include "access/htup_details.h"
#endif
#include "utils/builtins.h"

typedef struct Temp
{
	int seq;
} Temp;

Datum shortest_path(PG_FUNCTION_ARGS);



PG_FUNCTION_INFO_V1(shortest_path);
Datum
shortest_path(PG_FUNCTION_ARGS) {

 //int SPIcode = 0;
	Edge *edges=NULL;
	Edge *path=NULL;
	int num_edges,num_vertices,path_size=0;
	  FuncCallContext     *funcctx;
	  int                  call_cntr;
  int                  max_calls;
  TupleDesc            tuple_desc;
  PathElement  *ret_path = 0;
  int SPIcode = 0;
   int ret = -1;
	//first call of the function
	if (SRF_IS_FIRSTCALL()) {
		MemoryContext   oldcontext;
		funcctx = SRF_FIRSTCALL_INIT();
		oldcontext = MemoryContextSwitchTo(funcctx->multi_call_memory_ctx);
		//fetch the edges and construct the graph
		bool has_rcost=false;
    	has_rcost=PG_GETARG_BOOL(3);
		int read_data=fetch_data(text2char(PG_GETARG_TEXT_P(0)),&edges,&num_edges,has_rcost);
		if (read_data==-1)
		{
			 pfree(edges);
    		return finish(SPIcode, ret);
		}
		int source=PG_GETARG_INT64(1),target=PG_GETARG_INT64(2);
		elog(INFO, "EDGE COUNT: %d", num_edges);
		elog(INFO, "VERTEX COUNT: %d", num_vertices);
		//prints the path if the number of edges > 0
		if (num_edges>0)
		{
			//char buf[8192];
			//buf[0] = 0;
			//elog(INFO, "COUNT: %d", num_edges);
			int i;
			/*for (i = 0; i < num_edges; ++i)
			{
			//stroing it in a buffer
			//snprintf(buf + strlen (buf), sizeof(buf) - strlen(buf), " %d   %d  %s",edges[i].source,edges[i].dest," | ");
				//elog(INFO, "EDGES: %d %d", edges[i].source,edges[i].target);
			}*/
				path_size=compute_dijkstra(source,target,edges,num_vertices,num_edges,&path);
				elog(INFO,"Path Length %d",path_size);
				elog(INFO,"seq	|	source	|	target	|	cost");
				for (i = 0; i < path_size; ++i)
				{
					elog(INFO,"%d	|	%d	|	%d	|	%f",path[i].id,path[i].source,path[i].target,path[i].cost);
				}
				free(edges);
				free(path);
				//printing it as a buffer
	 			//elog(INFO, "EDGES: %s", buf);
			}
			else
			{
				elog(INFO,"ERROR: %s","No tuples found.");
				free(edges);
			}

			/* total number of tuples to be returned */
			funcctx->max_calls = path_size;
			funcctx->user_fctx = path;
			if (get_call_result_type(fcinfo, NULL, &tuple_desc) != TYPEFUNC_COMPOSITE)
				ereport(ERROR,
					(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
						errmsg("function returning record called in context "
							"that cannot accept type record")));

			funcctx->tuple_desc = tuple_desc;

			MemoryContextSwitchTo(oldcontext);

		}
/* stuff done on every call of the function */
  funcctx = SRF_PERCALL_SETUP();

  call_cntr = funcctx->call_cntr;
  max_calls = funcctx->max_calls;
  tuple_desc = funcctx->tuple_desc;
  ret_path = (PathElement*) funcctx->user_fctx;

  /* do when there is more left to send */
  if (call_cntr < max_calls) {

      /* clean up (this is not really necessary) */

      //SRF_RETURN_NEXT(funcctx, result);
  } else {
      /* do when there is no more left */
      if (ret_path) free(ret_path);
      SRF_RETURN_DONE(funcctx);
  }
}




Datum shortest_path_contracted(PG_FUNCTION_ARGS);



PG_FUNCTION_INFO_V1(shortest_path_contracted);
Datum
shortest_path_contracted(PG_FUNCTION_ARGS) {

 //int SPIcode = 0;
	Edge *edges=NULL;
	Edge *path=NULL;
	 int SPIcode = 0;
   int ret = -1;
	int num_edges=-1,num_vertices,path_size=0,total_tuples=-1,limit=-1;
	  FuncCallContext     *funcctx;
	  int                  call_cntr;
  int                  max_calls;
  TupleDesc            tuple_desc;
   Temp *ret_value;
	//first call of the function
	if (SRF_IS_FIRSTCALL()) {
		MemoryContext   oldcontext;
		funcctx = SRF_FIRSTCALL_INIT();
		oldcontext = MemoryContextSwitchTo(funcctx->multi_call_memory_ctx);
		//fetch the edges and construct the graph
		int limit=PG_GETARG_INT64(1);
		ret_value=(Temp*)malloc(sizeof(Temp));
		total_tuples=execq(text2char(PG_GETARG_TEXT_P(0)),limit);
		funcctx->max_calls = 1;
		elog(INFO,"Total tuple %d",total_tuples);
		ret_value->seq=total_tuples;

      	funcctx->user_fctx = ret_value;
			/* total number of tuples to be returned */
			if (get_call_result_type(fcinfo, NULL, &tuple_desc) != TYPEFUNC_COMPOSITE)
				ereport(ERROR,
					(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
						errmsg("function returning record called in context "
							"that cannot accept type record")));
			funcctx->tuple_desc = tuple_desc;
			MemoryContextSwitchTo(oldcontext);

		}
/* stuff done on every call of the function */
		elog(INFO,"Starting per call setup");
  funcctx = SRF_PERCALL_SETUP();

  call_cntr = funcctx->call_cntr;
  max_calls = funcctx->max_calls;
  tuple_desc = funcctx->tuple_desc;
ret_value = (Temp*) funcctx->user_fctx;
  /* do when there is more left to send */
  if (call_cntr < max_calls) {
HeapTuple    tuple;
      Datum        result;
      Datum *values;
      char *nulls;
      values = palloc(sizeof(Datum));
      nulls = palloc(sizeof(char));
      nulls[0]=' ';
      values[0]=Int32GetDatum(ret_value->seq);
      tuple = heap_formtuple(tuple_desc, values, nulls);
result = HeapTupleGetDatum(tuple);
      SRF_RETURN_NEXT(funcctx, result);
  } else {
      /* do when there is no more left */
      SRF_RETURN_DONE(funcctx);
  }
}