/*
Authors: Ali Haider, David Hurtgen
Email: alihaider1@outlook.com, dhurtgen@gmail.com
*/

#include "_src/_include/Map.h"
//#include "_src/_include/ProactiveRouting.h"
#include "_src/_include/ReactiveRouting.h"
//#include "_src/_include/HierarchicalRouting.h"
//#include "_src/_include/MLRouting.h"
#include <string>

int main()
{
	/*
	// Ali's calls
	//road,intersection, no of cars information
	std::string f = "_src/_include/_data/manhattan_actual.csv";

	ProactiveRouting<int> PR(f);
	
	// calculate shortest path from node u=1
	//PR.calculateDijkstrasSP(61);
	PR.printAdjacencyList();
	//PR.printAdjacencyMatrix();
	//PR.printMap();
	*/

	//David's calls
	std::string f = "../../traffic-management/_src/_include/_data/manhattan_test.csv";

	ReactiveRouting<int> RR(f);
	RR.scanForCongestion();
	

	return 0;
}