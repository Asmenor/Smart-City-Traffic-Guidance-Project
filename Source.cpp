/*
Author: Ali Haider
Email: alihaider1@outlook.com
*/

#include "_src/_include/Map.h"
#include "_src/_include/ProactiveRouting.h"
//#include "_src/_include/ReactiveRouting.h"
//#include "_src/_include/HierarchicalRouting.h"
//#include "_src/_include/MLRouting.h"
#include <string>

int main()
{

	//road,intersection, no of cars information
	std::string f = "_src/_include/_data/manhattan.csv";

	ProactiveRouting<int> PR(f);
	
	// calculate shortest path from node u=1
	PR.calculateDijkstrasSP(61);
	//PR.printAdjacencyMatrix();
	//PR.printMap();

	return 0;
}