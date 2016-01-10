#include "../src/myAstar.hpp"
#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <fstream>
#include <string>
#include <sstream>
#include <boost/lexical_cast.hpp>
using namespace std;
using namespace boost;
namespace patch
{
    template < typename T > std::string to_string( const T& n )
	{
		std::ostringstream stm ;
		stm << n ;
		return stm.str() ;
	}
}
int loadGraph(string edgeFile,Edge **edges,int64_t *num_vertices)
{

	int number_of_lines = 0;
	int64_t max_id=-1,min_id=1000000000;
	string line;
	ifstream myfile(edgeFile.c_str());
	ifstream myfile1(edgeFile.c_str());
	//ifstream myfile;
	//myfile.open("ways.txt");
	if (!myfile)
	{
		//throw new std::exception("Rule file could not be opened");
		cout << "cannot open" << endl;
	}
	while (getline(myfile, line))
		++number_of_lines;
	//cout << "line count " << number_of_lines << endl; 
	*edges=(Edge*)malloc(sizeof(Edge)*number_of_lines);
	int colid=0;
	int count=0;
	while(getline(myfile1,line))
	{
		std::stringstream  lineStream(line);
		std::string        cell;
		while(getline(lineStream,cell,'	'))
		{
			switch(colid)
			{
				case 0:
				(*edges)[count].id=atoi(cell.c_str());
				//cout << "id: " << cell << endl;
				break;
				case 1:
				(*edges)[count].source=atoi(cell.c_str());
				if((*edges)[count].source> max_id)
				{
					max_id=(*edges)[count].source;
				}
				if((*edges)[count].source < min_id)
				{
					min_id=(*edges)[count].source;
				}
				//cout << "source: " << cell << endl;
				break;
				case 2:
				(*edges)[count].target=atoi(cell.c_str());
				if((*edges)[count].target> max_id)
				{
					max_id=(*edges)[count].target;
				}
				if((*edges)[count].target < min_id)
				{
					min_id=(*edges)[count].target;
				}
				//cout << "target: " << cell << endl;
				break;
				case 3:
				(*edges)[count].s_x=atof(cell.c_str());
				break;
				case 4:
				(*edges)[count].s_y=atof(cell.c_str());
				break;
				case 5:
				(*edges)[count].t_x=atof(cell.c_str());
				break;
				case 6:
				(*edges)[count].t_y=atof(cell.c_str());
				break;
				case 7:
				(*edges)[count].cost=atof(cell.c_str());
				break;
				case 8:
				(*edges)[count].revcost=atof(cell.c_str());
				break;
			}
			colid++;
			colid=colid%9;
		}
		count++;
		//cout<< line << endl;
	}
	*num_vertices=max_id-min_id;
	myfile.close();
	myfile1.close();
	return number_of_lines;
}

typedef adjacency_list<vecS, vecS, undirectedS, Vertex,Edge> G;
void check(Edge *edges,int num_vertices,int num_edges,int level,string folder)
{
	string file=folder+"range";
	string line;
	typedef My_Astar<G> Graph;
	Graph g(UNDIRECTED,num_vertices);
	g.initialize_graph(edges,num_edges);
	g.contract_to_level(level);
	int line_count=0;
	for (int i = 1; i <=5; ++i)
	{
		
		ofstream out_file;
		string level_string=patch::to_string(level);
		string num_string=patch::to_string(i);
		cout << "Processing" << file+num_string << endl;
		string out_file_name=folder+"pathsize_"+level_string+"_"+num_string+".txt";
		out_file.open(out_file_name.c_str());
		cout << "Outputting to " << out_file_name << endl;
		string temp_file=file+num_string;
		ifstream input_vertices(temp_file.c_str());	
		int colid=0;
		while(getline(input_vertices,line))
		{
			std::stringstream  lineStream(line);
			std::string        cell;
			int64_t src,dest;
			while(getline(lineStream,cell,' '))
			{

				switch(colid)
				{
					case 0:
					src=atoi(cell.c_str());
					break;
					case 1:
					dest=atoi(cell.c_str());
					break;
				}
				colid++;
				colid=colid%2;
			}
			line_count++;
			//cout << src << "," << dest << endl;
			int64_t path_size1=0,path_size2=0;
			Edge *path1=NULL,*path2=NULL;
			//cout << "Astar on original graph" << endl;
			g.perform_astar(src,dest,&path1,path_size1);
			//cout << "Astar on contracted graph" << endl;
			g.astar_on_contracted(src,dest,&path2,path_size2);
			//cout  << path_size1 << "	" << path_size2 << endl;
			out_file << path_size1 << "	" << path_size2 << endl;
		//cout  << path_size1 << "	" << path_size2 << endl;
			//cout << "Lines processed :- " << line_count << endl;
			
		}

		out_file.close();
	}
	/*	Edge *path1=NULL,*path2=NULL;
		int64_t path_size1=0,path_size2=0;
		int64_t src=2007,dest=1573;
			//cout << "Astar on original graph" << endl;
			g.perform_astar(src,dest,&path1,path_size1);
			//cout << "Astar on contracted graph" << endl;
			g.astar_on_contracted(src,dest,&path2,path_size2);
			cout << path_size1 << "," << path_size2 << endl;*/
		}

		int main(int argc, char const *argv[])
		{
			Edge* edges;
			int64_t num_vertices=-1;
			string filestring=argv[1];
			cout << filestring << endl;
			string folder="/home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/src/tests/"+filestring+"/";
			string filename=folder+filestring+".txt";
			cout << "file " << filename << endl;
			int num_edges=loadGraph(filename,&edges,&num_vertices);
			num_vertices++;
			cout << "Number_vertices " << num_vertices << endl;
			check(edges,num_vertices,num_edges,0,folder);
			return 0;
		}




