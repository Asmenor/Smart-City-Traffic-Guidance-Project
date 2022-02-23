/*
Author: Ali Haider
Email: alihaider1@outlook.com
*/

#include "_include/Map.h"
#include "_include/ProactiveRouting.h"
#include <string>

int main()
{

	//road and intersection information
	std::string f = "_data/manhattan.dat";

	ProactiveRouting<int> PR(f);
	
	// calculate shortest path from node u=1
	//manhattan.calculateDijkstrasSP(61);
	//manhattan.printAdjList();
	PR.printMap();

	return 0;
}