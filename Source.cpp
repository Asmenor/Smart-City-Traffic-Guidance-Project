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
	// Ali's calls
	//road,intersection, no of cars information
	std::string f = "C:/Users/a-mehdipou/Documents/GitHub/traffic-management/_src/_include/_data/manhattan.csv";

	ProactiveRouting<int> PR(f);
	
	// calculate shortest path from node u=1
	PR.calculateDijkstrasSP(61);
	PR.printAdjacencyList();
	//PR.printAdjacencyMatrix();
	//PR.printMap();
	

	/*David's calls
	std::string f = "../../traffic-management/_src/_include/_data/manhattan.csv";

	ReactiveRouting<int> RR(f);
	RR.calculateSP(0, 99);
	RR.printAdjacencyMatrix();
	*/

	return 0;
}