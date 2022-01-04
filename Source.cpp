//adapted from: https://www.techiedelight.com/graph-implementation-using-stl/
//and https://www.includehelp.com/cpp-tutorial/dijkstras-algorithm.aspx

#include <iostream>
#include <vector>
#include "Road.h"
#include "Map.h"
using namespace std;

typedef pair<int, int> Pair;

// Graph Implementation using STL
int main()
{

	// construct graph
	string f = "data/manhattan.dat";

	Map<int> m(f);

	/*
	// print adjacency list representation of graph
	graph.printAdjList();

	// calculate shortest path from node u=1
	graph.calculateSP(0);
	//graph.printAdjMatrix();
	*/

	system("pause");
	return 0;
}