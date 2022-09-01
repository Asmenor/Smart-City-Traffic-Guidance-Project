/*
Author: Ali Haider
Email: alihaider1@outlook.com
*/

#include "_src/_include/Map.h"
#include "_src/_include/ProactiveRouting.h"
#include "_src/_include/DataGenerator.h"
//#include "_src/_include/ReactiveRouting.h"
//#include "_src/_include/HierarchicalRouting.h"
//#include "_src/_include/MLRouting.h"
#include <string>
#include <chrono>		//sleep
#include <thread>		//sleep

int main()
{
	// Ali's calls
	//road,intersection, no of cars information
	std::string f = "_src/_include/_data/manhattan_actual.csv";
	std::string f_ml = "_src/_include/_data/manhattan_test.csv";

	ProactiveRouting<int> PR(f);
	DataGenerator<int> DG;
	std::vector< Road<int> > newData;
	
	// calculate shortest path from node u=1
	//PR.calculateDijkstrasSP(61);
	//PR.printAdjacencyList();
	//PR.printAdjacencyMatrix(false);
	//PR.printMap();
	PR.generateMLSourceFileHeaderFromCSV(f_ml);

	if (DG.readPreviousData("manhattan_test.csv")){
		for(int ml_rows=0; ml_rows<2000; ml_rows++){
			DG.assignNewData(5, 25, 100, 300);
			newData = DG.getData();
			PR.updateMLSourceFileFromVector(newData);

			using namespace std::this_thread; // sleep_for, sleep_until
    		using namespace std::chrono; // nanoseconds, system_clock, seconds

    		sleep_for(seconds(1));
			sleep_until(system_clock::now() + seconds(1));
		}
	}

	
	/*David's calls
	std::string f = "../../traffic-management/_src/_include/_data/manhattan.csv";

	ReactiveRouting<int> RR(f);
	RR.calculateSP(0, 99);
	RR.printAdjacencyMatrix();
	*/

	return 0;
}