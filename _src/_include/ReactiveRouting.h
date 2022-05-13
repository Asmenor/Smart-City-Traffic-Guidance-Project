#ifndef _REACTIVE_CLASS
#define _REACTIVE_CLASS

#include "Map.h"
#include "DataGenerator.h"

const int MAX_NUM_CARS = 377;
const int MIN_SPEED = 5;

template <class V>
class ReactiveRouting {

	Map<int> manhattan;

public:
	ReactiveRouting(std::string&);
	void scanForCongestion();
	float calculateCF(const int&, const float&, const float&, const int&) const;
	void printAdjacencyList(const std::vector<Road<V>*>&) const;
	void printCongestedRoads(Road<V>*) const;
	void printDirectPTD(const std::vector<Road<V>*>&, const int&, const float&) const;
	void calculateLCP(const V&, const V&, std::vector<Road<V>*>, float&);
	int getNextAdjIntersection(int, const std::vector<Road<V>*>&) const;
	float getNextAdjCongestion(int, std::vector<Road<V>*>&, bool&) const;
	int findLeastCongestedIntersection(bool[], float[]) const;
	void printPathToDest(std::vector<Road<V>*>[], const V&, const float&) const;
	void generateNewMap();
};

//constructor
template<class V>
ReactiveRouting<V>::ReactiveRouting(std::string& f) {
	// load f and create Map object
	manhattan = Map<V>(f);
}

/*
This function utilizes 3 primary data structures: a vector of all roads, a linked list of
congested roads, and an adjacency list of roads. The adjacency list is a vector, with
each member containing a linked list of roads adjacent from an intersection of the
map. (Some texts describe this relationship as 'adjacent to'.) At vector[0] are all road
segments beginning at intersection 0, with traffic flowing away from the intersection.

The function serves to scan all roads for congested road segments, place them into the
vector of congested roads, and build the adjacency list to be used by the least congested
path algorithm that follows. Once the congested roads vector is built, it is parsed to
identify lengths of congestion (more than 1 contiguous road segment of congestion with the
same flow of traffic) and the least congested path algorithm is called for each area of
congestion, be it single road segments or lengths of contiguous roads. Any congested road 
segment along the edge of the graph is thrown out to eliminate the potential for "falling 
off the map".
*/

template<class V>
void ReactiveRouting<V>::scanForCongestion() {
	// variables for roads
	std::string nme;
	V src;
	V dst;
	int nc;
	float ls;
	float v;
	int nl = 1;
	int limit;
	float congestion;

	// boolean for congestion in the grid
	bool congestion_exists = false;
	// for comparing timings for direct path vs. least congested path
	float direct_path_time = 0.0;
	float lcp_time = 0.0;

	// data structures
	// all roads in a vector
	std::vector<Road<V>*> Roads = manhattan.getRoads();
	// adjacency list of roads, each member is the head of a linked list of adjacent roads
	std::vector<Road<V>*> adj_list;
	// linked list of congested roads
	Road<V>* congested_roads = nullptr;
	Road<V>* curr = nullptr;

	// initialize the adjacency list
	for (int i = 0; i < no_intersections; i++) {
		nme = "self";
		src = i;
		dst = i;
		nc = 0;
		ls = 0.0;
		v = 0.0;
		limit = 0;
		congestion = 0.0;

		adj_list.push_back(new Road<V>(nme, src, dst, nc, ls, v, nl, limit, congestion));
		curr = adj_list.at(i);
	}

	// push congested roads into the LL of congested_roads, 
	// complete adjacency list
	for (auto& road : Roads) {
		nme = road->getName();
		src = road->getSrc();
		dst = road->getDst();
		nc = road->getNumCars();
		ls = road->getLength();
		v = road->getAvgSpeed();
		limit = road->getSpeedLimit();
		congestion = road->getCongestion();

		// push congested roads into the linked list of congested roads
		// must be ordered by ascending src
		// don't push "border" roads in
		if (road->getSrc() > (ROWS - 1) && road->getDst() > (ROWS - 1) &&
			road->getSrc() < (no_intersections - ROWS) && road->getDst() < (no_intersections - ROWS) &&
			road->getSrc() % ROWS != 0 && road->getDst() % ROWS != 0 &&
			road->getSrc() % ROWS != (ROWS - 1) && road->getDst() % ROWS != (ROWS - 1)) {
			if (road->getCongestion() > 0.65) {
				curr = congested_roads;
				// if the list is empty...
				if (congested_roads == nullptr) {
					congested_roads = new Road<V>(nme, src, dst, nc, ls, v, nl, limit, congestion);
				}
				// if the new road src value is less than 1st road src value in the list
				else if (road->getSrc() < curr->getSrc()) {
					Road<V>* temp = new Road<V>(nme, src, dst, nc, ls, v, nl, limit, congestion);
					temp->setNextRoad(curr);
					congested_roads = temp;
				}
				// all others
				else {
					while (curr->getNextRoad() != nullptr) {
						if (curr->getNextRoad()->getSrc() > road->getSrc()) break;
						else curr = curr->getNextRoad();
					}
					// now that we've found our spot...
					Road<V>* temp = new Road<V>(nme, src, dst, nc, ls, v, nl, limit, congestion);
					temp->setNextRoad(curr->getNextRoad());
					curr->setNextRoad(temp);
				}
				congestion_exists = true;
			}
		}

		// complete adjacency list
		curr = adj_list.at(src);
		while (curr->getNextRoad() != nullptr) curr = curr->getNextRoad();
		curr->setNextRoad(new Road<V>(nme, src, dst, nc, ls, v, nl, limit, congestion));
	}

	// insert dummy road at end of each LL in the adjacency list (src/dst of 1000)
	for (int i = 0; i < no_intersections; i++) {
		nme = "dummy road";
		src = 1000;
		dst = 1000;
		nc = 0;
		ls = 0.0;
		v = 0;
		limit = 0;
		congestion = 0.0;

		curr = adj_list.at(i);
		while (curr->getNextRoad() != nullptr) curr = curr->getNextRoad();
		curr->setNextRoad(new Road<V>(nme, src, dst, nc, ls, v, nl, limit, congestion));
	}

	printAdjacencyList(adj_list);

	printCongestedRoads(congested_roads);

	// identify congested lengths (more than 1 contiguous road with congestion) 
	// and set start/end for routing
	V start;
	V end;
	V match;
	int traffic_flow = 0;
	Road<V>* root = congested_roads;
	Road<V>* current = nullptr;
	Road<V>* holding_ptr = nullptr;

	// direct path to destination vector for comparison to least congested path
	std::vector<Road<V>*> directPTD;

	// nested loops for assembling contiguous segments of congestion
	if (congestion_exists) {
		while (root != nullptr) {
			// reset direct path time
			direct_path_time = 0.0;
			// push root into direct path to destination
			nme = root->getName();
			src = root->getSrc();
			dst = root->getDst();
			nc = root->getNumCars();
			ls = root->getLength();
			v = root->getAvgSpeed();
			limit = root->getSpeedLimit();
			congestion = root->getCongestion();
			directPTD.push_back(new Road<V>(nme, src, dst, nc, ls, v, nl, limit, congestion));
			holding_ptr = root;
			current = root->getNextRoad();
			// north, 0
			if (root->getSrc() == root->getDst() - 1) traffic_flow = 0;
			// south, 1
			else if (root->getSrc() == root->getDst() + 1) traffic_flow = 1;
			// east, 2
			else if (root->getSrc() < root->getDst()) traffic_flow = 2;
			// west, 3
			else if (root->getSrc() > root->getDst()) traffic_flow = 3;

			// set start and end variables
			start = root->getSrc();
			end = root->getDst();

			// northern flow (intersection numbers increase by 1)
			if (traffic_flow == 0) {
				match = end;

				while (current != nullptr) {
					if (current->getSrc() == match && current->getSrc() == current->getDst() - 1) {
						end = current->getDst();
						match = end;
						// push into direct path to destination
						nme = current->getName();
						src = current->getSrc();
						dst = current->getDst();
						nc = current->getNumCars();
						ls = current->getLength();
						v = current->getAvgSpeed();
						limit = current->getSpeedLimit();
						congestion = current->getCongestion();
						directPTD.push_back(new Road<V>(nme, src, dst, nc, ls, v, nl, limit, congestion));
						Road<V>* temporary = current;
						current = current->getNextRoad();
						holding_ptr->setNextRoad(current);
						delete temporary;
					}

					else {
						holding_ptr = holding_ptr->getNextRoad();
						current = current->getNextRoad();
					}
				}
			}

			// eastern flow (intersection numbers increase by ROWS)
			if (traffic_flow == 2) {
				match = end;

				while (current != nullptr) {
					if (current->getSrc() == match && current->getSrc() == current->getDst() - ROWS) {
						end = current->getDst();
						match = end;
						// push into direct path to destination
						nme = current->getName();
						src = current->getSrc();
						dst = current->getDst();
						nc = current->getNumCars();
						ls = current->getLength();
						v = current->getAvgSpeed();
						limit = current->getSpeedLimit();
						congestion = current->getCongestion();
						directPTD.push_back(new Road<V>(nme, src, dst, nc, ls, v, nl, limit, congestion));
						Road<V>* temporary = current;
						current = current->getNextRoad();
						holding_ptr->setNextRoad(current);
						delete temporary;
					}

					else {
						holding_ptr = holding_ptr->getNextRoad();
						current = current->getNextRoad();
					}
				}
			}

			// southern flow (intersection numbers decrease by 1)
			if (traffic_flow == 1) {
				match = start;

				while (current != nullptr) {
					if (current->getDst() == match && current->getSrc() == current->getDst() + 1) {
						start = current->getSrc();
						match = start;
						//push into direct path to destination
						nme = current->getName();
						src = current->getSrc();
						dst = current->getDst();
						nc = current->getNumCars();
						ls = current->getLength();
						v = current->getAvgSpeed();
						limit = current->getSpeedLimit();
						congestion = current->getCongestion();
						directPTD.push_back(new Road<V>(nme, src, dst, nc, ls, v, nl, limit, congestion));
						Road<V>* temporary = current;
						current = current->getNextRoad();
						holding_ptr->setNextRoad(current);
						delete temporary;
					}

					else {
						holding_ptr = holding_ptr->getNextRoad();
						current = current->getNextRoad();
					}
				}
			}

			// western flow (intersection numbers decrease by ROWS)
			if (traffic_flow == 3) {
				match = start;

				while (current != nullptr) {
					if (current->getDst() == match && current->getSrc() == current->getDst() + ROWS) {
						start = current->getSrc();
						match = start;
						//push into direct path to destination
						nme = current->getName();
						src = current->getSrc();
						dst = current->getDst();
						nc = current->getNumCars();
						ls = current->getLength();
						v = current->getAvgSpeed();
						limit = current->getSpeedLimit();
						congestion = current->getCongestion();
						directPTD.push_back(new Road<V>(nme, src, dst, nc, ls, v, nl, limit, congestion));
						Road<V>* temporary = current;
						current = current->getNextRoad();
						holding_ptr->setNextRoad(current);
						delete temporary;
					}

					else {
						holding_ptr = holding_ptr->getNextRoad();
						current = current->getNextRoad();
					}
				}
			}

			// set start and end based on traffic flow
			// north
			if (traffic_flow == 0) {
				start = start - 1;
				// add first segment from start
				for (Road<V>* rd : Roads) {
					if (rd->getSrc() == start && rd->getDst() == start + 1) {
						directPTD.insert(directPTD.begin(), rd);
						break;
					}
				}
			}

			// south
			else if (traffic_flow == 1) {
				start = start + 1;
				// add first segment from start
				for (Road<V>* rd : Roads) {
					if (rd->getSrc() == start && rd->getDst() == start - 1) {
						directPTD.insert(directPTD.end(), rd);
						break;
					}
				}
			}

			// east
			else if (traffic_flow == 2) {
				start = start - ROWS;
				// add first segment from start
				for (Road<V>* rd : Roads) {
					if (rd->getSrc() == start && rd->getDst() == start + ROWS) {
						directPTD.insert(directPTD.begin(), rd);
						break;
					}
				}
			}

			// west
			else if (traffic_flow == 3) {
				start = start + ROWS;
				// add first segment from start
				for (Road<V>* rd : Roads) {
					if (rd->getSrc() == start && rd->getDst() == start - ROWS) {
						directPTD.insert(directPTD.end(), rd);
						break;
					}
				}
			}

			// calculate direct path travel time
			for (int i = 0; i < directPTD.size(); i++) {
				direct_path_time += (directPTD.at(i)->getLength()) / (directPTD.at(i)->getAvgSpeed());
			}
			// convert hours to minutes
			direct_path_time = direct_path_time * 60;

			// print directPTD
			std::cout << "\nDirect path through congested area from " <<
				start << " to " << end << ": \n";
			printDirectPTD(directPTD, traffic_flow, direct_path_time);

			// run the LCP algorithm
			std::cout << "\nFinding path with lowest congestion total from " << start << " to " << end << "... \n";
			calculateLCP(start, end, adj_list, lcp_time);

			// compare direct path time to lcp time
			if (direct_path_time > lcp_time) {
				std::cout << "Taking the path with the lowest congestion total will save you approximately " <<
					direct_path_time - lcp_time << " minutes.\n";
			}

			// remove first road from the list congested roads and advance root
			Road<V>* temporary = root;
			root = root->getNextRoad();
			delete temporary;
			// clear out directPTD
			directPTD.clear();
		}
	}
	else std::cout << "No congestion currently exists." << endl;
}

/*
A function for calculating congestion for any road segment using number of cars, the
length of the road segment, and the average speed of the cars on the segment. Currently,
this function is not used as congestion is read in from the .csv file. The function
remains for potential future implementation.
*/

template<class V>
float ReactiveRouting<V>::calculateCF(const int& nc, const float& ls, const float& v, const int& limit) const {
	// not normalized
	float nncf;
	// normalized
	float ncf;
	nncf = (nc / (MAX_NUM_CARS * ls)) / (v / limit);
	ncf = nncf / (limit / MIN_SPEED);
	return ncf;
}

/*
Prints the adjacency list. The head of each vector showing an intersection as adjacent
from itself is not printed. Nor is the dummy road at the end of the list.
*/

template<class V>
void ReactiveRouting<V>::printAdjacencyList(const std::vector<Road<V>*>& al) const {
	std::cout << std::endl << "Adjacency list..." << std::endl;
	for (Road<V>* rd : al) {
		Road<V>* curr = rd;
		// don't print the root node
		curr = curr->getNextRoad();
		// don't print the dummy node
		while (curr->getNextRoad() != nullptr) {
			std::cout << curr->getSrc() << " --> " << curr->getDst() <<
				" (c: " << std::setprecision(4) << curr->getCongestion() << ")" << "\t";
			curr = curr->getNextRoad();
		}
		std::cout << std::endl;
	}
}

/*
Prints all road segments currently congested.
*/

template<class V>
void ReactiveRouting<V>::printCongestedRoads(Road<V>* cr) const {
	std::cout << "\nCongested road segments: \n";
	Road<V>* curr = cr;
	while (curr != nullptr) {
		std::cout << curr->getName() << " from " << curr->getSrc() << " to " << curr->getDst() << std::endl;
		curr = curr->getNextRoad();
	}
}

/*
Prints direct path through congested area with estimated travel time.
*/

template<class V>
void ReactiveRouting<V>::printDirectPTD(const std::vector<Road<V>*>& dptd, const int& tf, const float& dpt) const {
	// north or east
	if (tf == 0 || tf == 2) {
		for (int i = 0; i < dptd.size(); i++) {
			std::cout << dptd.at(i)->getSrc() << " --> " << dptd.at(i)->getDst() <<
				", segment distance: " << dptd.at(i)->getLength() << " miles\n";
		}
		std::cout << "Est travel time: " << dpt << " minutes\n";
	}
	// south or west (print backward)
	else if (tf == 1 || tf == 3) {
		for (int i = dptd.size() - 1; i >= 0; i--) {
			std::cout << dptd.at(i)->getSrc() << " --> " << dptd.at(i)->getDst() <<
				", segment distance: " << dptd.at(i)->getLength() << " miles\n";
		}
		std::cout << "Est travel time: " << dpt << " minutes\n";
	}
}

/*
Calculates the least congested path between two intersections as determined by scanForCongestion()
using 4 primary data structures: the adjacency list passed from scanForCongestion(), an array
marking intersections whose least congested path from the source has been found, an array of
congestion values for each intersection from the source (continually updated until the LCP is
found), and an array of vectors of roads for holding the specific path from source to destination.

The adjacency list is used as the primary data structure for running Dijkstra's algorithm.
Rather than iterating through an adjacency matrix (a common method for running the algorithm),
the adjacency list is used to determine all roads adjacent from each intersection visited. While
this method is programmatically a bit more intensive than the use of an adjacency matrix, it
provides two advantages: only roads adjacent from the given intersection are iterated through
(rather than all intersections); all information pertinent to the user for output is contained
in the structure, not just the congestion value (name, road segment length, etc.).
*/

template<class V>
void ReactiveRouting<V>::calculateLCP(const V& s, const V& t, std::vector<Road<V>*> al, float& lcpt) {

	std::vector<Road<V>*> adj_list = al;
	bool found[no_intersections];						//intersections where LCP has been found
	float segment_congestion[no_intersections];			//array of congestion values for visited intersections
	int least_congested_intrsctn;
	bool adjIntersectionsRemain;
	std::vector<Road<V>*> pathToDest[no_intersections];	//array of vectors of type Road
	int mark;

	for (int k = 0; k < no_intersections; k++) {
		found[k] = false;
		segment_congestion[k] = inf;
	}

	found[s] = true;
	segment_congestion[s] = 0.0;
	least_congested_intrsctn = s;

	// variables for roads pushed into pathToDest
	std::string nme;
	V src;
	V dst;
	int nc;
	float ls;
	float v;
	int nl = 1;
	int limit;
	float congestion;
	Road<V>* curr = nullptr;

	while (least_congested_intrsctn != t) {

		adjIntersectionsRemain = true;
		while (adjIntersectionsRemain) {
			int nextAdjIntersection = getNextAdjIntersection(least_congested_intrsctn, adj_list);
			float nextAdjCongestion = getNextAdjCongestion(least_congested_intrsctn, adj_list, adjIntersectionsRemain);
			// place congestion in segment_congestion[] if less than current value
			if ((segment_congestion[least_congested_intrsctn] + nextAdjCongestion < segment_congestion[nextAdjIntersection])
				&& (!found[nextAdjIntersection])) {
				segment_congestion[nextAdjIntersection] = segment_congestion[least_congested_intrsctn] + nextAdjCongestion;
				// update path
				curr = adj_list.at(least_congested_intrsctn);
				// if dummy is at the end, get to second to last road
				if (!adjIntersectionsRemain) {
					while (curr->getNextRoad()->getNextRoad() != nullptr) {
						curr = curr->getNextRoad();
					}
				}
				// otherwise, get to last road
				else {
					while (curr->getNextRoad() != nullptr) {
						curr = curr->getNextRoad();
					}
				}
				// set values for addition to pathToDest[]
				nme = curr->getName();
				src = curr->getSrc();
				dst = curr->getDst();
				nc = curr->getNumCars();
				ls = curr->getLength();
				v = curr->getAvgSpeed();
				limit = curr->getSpeedLimit();
				congestion = curr->getCongestion();
				// copy path from lci
				pathToDest[nextAdjIntersection] = pathToDest[least_congested_intrsctn];
				// add new road to path
				pathToDest[nextAdjIntersection].push_back(new Road<V>(nme, src, dst, nc, ls, v, nl, limit, congestion));
			}
		}
		// mark least congested unvisited intersection in segment_congestion[]
		mark = findLeastCongestedIntersection(found, segment_congestion);
		found[mark] = true;
		least_congested_intrsctn = mark;
	}
	std::cout << "\nLowest total congestion: " << segment_congestion[t] << std::endl;

	// calculate lcp time
	lcpt = 0.0;
	for (int j = 0; j < pathToDest[t].size(); j++) {
		curr = pathToDest[t].at(j);
		lcpt += curr->getLength() / curr->getAvgSpeed();
	}
	// hours to minutes
	lcpt = lcpt * 60;

	// print path
	printPathToDest(pathToDest, t, lcpt);
}

/*
Used in conjunction with calculateLCP(). Returns the destination intersection of the next road
adjacent from the source intersection.
*/

template<class V>
int ReactiveRouting<V>::getNextAdjIntersection(int lci, const std::vector<Road<V>*>& al) const {
	Road<V>* curr = al.at(lci);
	int result = curr->getNextRoad()->getDst();
	return result;
}

/*
Used in conjunction with calculateLCP(). Returns the congestion value of each road adjacent
from the source intersection (1 per call). The road is cycled to the back of the list
as it's congestion value is returned. Once the dummy road is hit, which signifies the last
road segment adjacent from the source intersection has been called, it is cycled to the back,
thereby resetting the list for further calls to calculateLCP().
*/

template<class V>
float ReactiveRouting<V>::getNextAdjCongestion(int lci, std::vector<Road<V>*>& al, bool& air) const {
	Road<V>* root = al.at(lci);
	Road<V>* curr = root;
	Road<V>* temp = root->getNextRoad();
	Road<V>* dummy = nullptr;

	float result = temp->getCongestion();

	while (curr->getNextRoad() != nullptr) curr = curr->getNextRoad();
	root->setNextRoad(temp->getNextRoad());
	curr->setNextRoad(temp);
	temp->setNextRoad(nullptr);

	// look for dummy node, mark "air" false and move dummy node to the end if found
	if (root->getNextRoad()->getDst() == 1000) {
		air = false;
		// move curr to the end of the list
		curr = curr->getNextRoad();
		// hold the dummy node
		dummy = root->getNextRoad();
		root->setNextRoad(dummy->getNextRoad());
		// move dummy node to the end of the LL
		curr->setNextRoad(dummy);
		dummy->setNextRoad(nullptr);
	}
	return result;
}

/*
Returns the least congested intersection from the segment_congestion[] array that has not already
been marked.
*/

template<class V>
int ReactiveRouting<V>::findLeastCongestedIntersection(bool found[], float segment_congestion[]) const {
	float min = inf;
	int lci;
	for (int i = 0; i < no_intersections; i++) {
		if (!found[i] && segment_congestion[i] <= min) {
			min = segment_congestion[i];
			lci = i;
		}
	}
	return lci;
}

/*
Prints the path from source to destination with estimated travel time.
*/

template<class V>
void ReactiveRouting<V>::printPathToDest(std::vector<Road<V>*> pathToDest[], const V& t, const float& lcpt) const {
	Road<V>* curr = nullptr;
	std::cout << "\nPath is: \n";
	for (int j = 0; j < pathToDest[t].size(); j++) {
		curr = pathToDest[t].at(j);
		std::cout << curr->getSrc() << " --> " << curr->getDst() << ", segment distance: " << curr->getLength() << " miles\n";
	}
	std::cout << "Est travel time: " << lcpt << " minutes\n";
}

/*
Generates a map with updated variable information. This functionality will ultimately be
moved to the Map.h class, and is not currently used.
*/

template<class V>
void ReactiveRouting<V>::generateNewMap() {
	DataGenerator dg;
	if (dg.readPreviousData("manhattan.csv"))
	{
		dg.assignNewData(20, 30, 10, 30, 0.6, 0.8);
		if (!dg.writeNewData("manhattan_test.csv"))
			cout << "Error in writing the file!" << endl;
		else
			cout << "New data generated." << endl;
	}
}

#endif