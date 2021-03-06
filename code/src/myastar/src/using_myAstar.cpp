#include "myAstar.hpp"
#include <iostream>
#include <boost/graph/adjacency_list.hpp>
using namespace std;
using namespace boost;
typedef adjacency_list<vecS, vecS, directedS, Vertex,Edge> G;
int main(int argc, char const *argv[])
{
	/* code */
	typedef My_Astar<G> Graph;
	Graph g(DIRECTED,3);
	Edge *edges=NULL;
	edges=(Edge*)malloc(2*sizeof(Edge));
	edges[0].id=0;
	edges[0].source=0;
	edges[0].target=1;
	edges[0].cost=5;
	edges[0].revcost=-1;

	edges[1].id=1;
	edges[1].source=1;
	edges[1].target=2;
	edges[1].cost=4;
	edges[1].revcost=-1;
	g.initialize_graph(edges,2);
	//g.remove_vertex(0);
	Edge *path=NULL;
	int64_t path_size=0;
	g.perform_astar(0,1,&path,path_size);
	g.print_path(&path,path_size);
	return 0;
}