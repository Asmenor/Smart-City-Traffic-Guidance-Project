/*
Author: Ali Haider
Email: alihaider1@outlook.com
*/

#include "_include/Map.h"

int main()
{

	// construct graph by reading data from file
	std::string f = "_data/manhattan.dat";
	Map<int> manhattan(f);

	// calculate shortest path from node u=1
	manhattan.calculateSP(61);
	//manhattan.printAdjList();

	return 0;
}