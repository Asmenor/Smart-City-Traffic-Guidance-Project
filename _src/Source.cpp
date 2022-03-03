/*
Author: Ali Haider
Email: alihaider1@outlook.com
*/

#include "_include/Map.h"
#include "_include/ProactiveRouting.h"
//#include "_include/ReactiveRouting.h"
//#include "_include/HierarchicalRouting.h"
//#include "_include/MLRouting.h"
#include <string>

int main()
{

	//road,intersection, no of cars information
	std::string f = "manhattan.csv";

	ProactiveRouting<int> PR(f);
	
	// calculate shortest path from node u=1
	//PR.calculateDijkstrasSP(61);
	//PR.printAdjacencyMatrix();
	//PR.printMap();

	return 0;
}