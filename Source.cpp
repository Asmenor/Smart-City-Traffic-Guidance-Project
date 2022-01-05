/* djikstras algorithm adapted from
https://www.includehelp.com/cpp-tutorial/dijkstras-algorithm.aspx
*/

#include "_include/Map.h"

int main()
{

	// construct graph by reading data from file
	std::string f = "_data/manhattan.dat";
	Map<int> manhattan(f);

	// calculate shortest path from node u=1
	manhattan.calculateSP(61);
	manhattan.printAdjList();

	return 0;
}