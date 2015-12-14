#ifndef GRAPH_MINIMIZER_H_
#define GRAPH_MINIMIZER_H_


#include <deque>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <iostream>
#include <boost/config.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include "../../common/src/myGraph.hpp"
#include "../../common/src/structs.h"
using namespace std;
using namespace boost;
template < class G >
class Graph_Minimizer
:public My_base_graph<G> {
public:
	My_base_graph<G> *reduced_graph;
  //constrictor for this class which inherits the base graph
	explicit Graph_Minimizer(graphType gtype, const int initial_size)
	:My_base_graph<G>(gtype, initial_size) {
		reduced_graph=new My_base_graph<G>(gtype,initial_size);
	}
	typedef typename boost::graph_traits < G >::vertex_descriptor V;
	typedef typename boost::graph_traits < G >::edge_descriptor E;
	typedef typename boost::graph_traits < G >::vertex_iterator V_i;

  //typedef typename std::map<V,E> removed_edges;
	typedef typename std::map<V,stack<V> > removed_vertices;
	typedef typename std::map< int64_t, std::vector<V> > degree_to_V;
	typedef typename std::map< int64_t, std::vector<V> >::iterator degree_to_V_i;
	typedef typename std::vector<V>::iterator Q_i;
	typedef typename boost::graph_traits < G >::out_edge_iterator EO_i;

	removed_vertices removedVertices;

  //initializes the graph with the given edges
	void
	initialize_graph(Edge *data_edges, int64_t count) {
		this->insert_data(data_edges, count);
		reduced_graph->insert_data(data_edges,count);
	}


	void remove_1_degree_vertices()
	{
		EO_i out,out_end;
		V front=reduced_graph->degree_to_V_map[1].front();
		while (reduced_graph->graph[front].degree==1)
		{
			for (boost::tie(out, out_end) = out_edges(front, reduced_graph->graph);
				out != out_end; ++out) 
			{
				V s=source(*out, reduced_graph->graph);
				V t=target(*out, reduced_graph->graph);
				reduced_graph->remove_vertex(s);
				reduced_graph->degree_to_V_map[1].erase(reduced_graph->degree_to_V_map[1].begin(),
					reduced_graph->degree_to_V_map[1].begin()+1);
				reduced_graph->graph[t].contractions++;
				int prev_target_degree=reduced_graph->graph[t].degree;
				reduced_graph->graph[t].degree--;
				int final_target_degree=prev_target_degree-1;
				reduced_graph->degree_to_V_map[final_target_degree].push_back(t);
				removedVertices[t].push(s);
			}
			front=reduced_graph->degree_to_V_map[1].front();
		}
	}

	int getreducedGraph(Edge **reduced_list)
	{
		int reduced_size=(int)num_edges(reduced_graph->graph);
		*reduced_list=(Edge *)malloc(sizeof(Edge)*reduced_size);
		V_i vi;
		EO_i out,out_end;
		int count=0;
		for (vi = vertices(reduced_graph->graph).first; vi != vertices(reduced_graph->graph).second; ++vi) {
			for (boost::tie(out, out_end) = out_edges(*vi, reduced_graph->graph);
				out != out_end; ++out) {
				(*reduced_list)[count].id=reduced_graph->graph[*out].id;
			(*reduced_list)[count].source=reduced_graph->graph[source(*out, reduced_graph->graph)].id;
			(*reduced_list)[count].target=reduced_graph->graph[target(*out, reduced_graph->graph)].id;
			(*reduced_list)[count].cost=reduced_graph->graph[*out].cost;
			count++;
		}
	}
	return count;
}

void contract_to_level(int level)
{
	switch(level)
	{
		case 0 :
		this->remove_1_degree_vertices(); 
		break;
		default :
		//	do nothing;
		break;
	}
}

};
#endif