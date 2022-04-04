#ifndef _REACTIVE_CLASS
#define _REACTIVE_CLASS

#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "DataGenerator.h"

const int MAX_NUM_CARS = 352;
const int SPEED_LIMIT = 35;

template <class V>
class ReactiveRouting {

	Map<int> manhattan;

public:
	ReactiveRouting(std::string&);
	int findLeastCongestedIntersection(bool[], float[]);
	void calculateLCP(const V&, const V&, std::vector<Intersection<V>*>);
	void printAllRoads() const;
	void printAdjacencyMatrix() const;
	void printAdjacencyList(const std::vector<Intersection<V>*>&) const;
	float calculateCF(const int& c, const float& l, const float& v);
	//float calculateCF(const float& v);
	int getNextAdjIntersection(int, const std::vector<Intersection<V>*>&) const;
	float getNextAdjWeight(int, std::vector<Intersection<V>*>&, bool&);
	void generateNewMap();
	void scanForCongestion();
	void printCongestedRoads(Road<V>*) const;
};

//constructor
template<class V>
ReactiveRouting<V>::ReactiveRouting(std::string& f) {
	//load f and create Map
	manhattan = Map<V>(f);
}

template<class V>
void ReactiveRouting<V>::printAllRoads() const {
	manhattan.printRoads();
}

template<class V>
void ReactiveRouting<V>::printAdjacencyMatrix() const {
	manhattan.printAdjMatrix(true);
}

template<class V>
void ReactiveRouting<V>::scanForCongestion() {

	std::string nme;
	V src;
	V dst;
	int nc;						//number of cars
	float ls;					//length of road segment
	float v;					//avg speed of cars
	int nl = 1;					//number of lanes, always 1 for me
	int limit = SPEED_LIMIT;	//speed limit
	float congestion;
	float** adj_matrix = manhattan.getAdjacencyMatrix();
	std::vector<Road<V>*> Roads = manhattan.getRoads();
	//linked list of congested roads
	Road<V>* congested_roads = nullptr;
	//adjacency list of intersections (only for the LCP algo)
	std::vector<Intersection<V>*> adj_list;
	//adjacency list of all roads
	std::vector<Road<V>*> adj_list_roads = manhattan.getAdjacencyList();

	// set road congestion, update adj_matrix, push congested roads into the LL (congested_roads)
	for (auto road : Roads) {
		nme = road->getName();
		src = road->getSrc();
		dst = road->getDst();
		nc = road->getNumCars();
		ls = road->getLength();
		v = road->getAvgSpeed();

		congestion = calculateCF(nc, ls, v);
		//congestion = calculateCF(v);
		// override road congestion values
		road->setCongestion(congestion);
		// push congested roads into the linked list of congested roads
		if (road->getCongestion() > 0.65) {
			// if the list is empty...
			if (congested_roads == nullptr) {
				congested_roads = new Road<V>(nme, src, dst, nc, ls, v, nl, limit);
			}
			// all subsequent roads...
			else {
				Road<V>* curr = congested_roads;
				while (curr->getNextRoad() != nullptr) curr = curr->getNextRoad();
				curr->setNextRoad(new Road<V>(nme, src, dst, nc, ls, v, nl, limit));
			}
		}
		// update adjacency matrix
		adj_matrix[src][dst] = congestion;
	}

	// update adj_list of intersections from adj_matrix
	Intersection<V>* curr = nullptr;
	for (int i = 0; i < no_intersections; i++) {
		src = i;
		adj_list.push_back(new Intersection<V>(src));
		for (int j = 0; j < no_intersections; j++)
			if (adj_matrix[i][j] > 0.00 && adj_matrix[i][j] != inf) {
				curr = adj_list.at(src);
				while (curr->getNextIntersection() != nullptr) {
					curr = curr->getNextIntersection();
				}
				dst = j;
				congestion = adj_matrix[i][j];
				curr->setNextIntersection(new Intersection<V>(dst, congestion));
			}
		// insert dummy node at end of each LL (value of infinity)
		dst = inf;
		curr = curr->getNextIntersection();
		curr->setNextIntersection(new Intersection<V>(dst));
	}

	printAdjacencyList(adj_list);

	printCongestedRoads(congested_roads);

	// identify congested lengths (more than 1 contiguous road with congestion) 
	// and set start/end for routing
	V start;
	V end;
	V match;									//for finding adjacent congested lengths
	int traffic_flow = 0;						//directional information
	Road<V>* root = congested_roads;			//always marks the beginning of the list
	Road<V>* current = nullptr;					//continually cycles through the list
	Road<V>* holding_ptr = nullptr;				//for deleting adjacent roads as they're matched up to root

	// outer loop
	while (root != nullptr) {
		holding_ptr = root;
		current = root->getNextRoad();
		// obtain direction of traffic flow
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

		// northern or eastern flow (intersection numbers increase)
		if (traffic_flow == 0 || traffic_flow == 2) {
			match = end;

			while (current != nullptr) {
				if (current->getSrc() == match) {
					end = current->getDst();
					match = end;
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

		// southern or western flow (intersection numbers decrease)
		if (traffic_flow == 1 || traffic_flow == 3) {
			match = start;

			while (current != nullptr) {
				if (current->getDst() == match) {
					start = current->getSrc();
					match = start;
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
			end = end + 1;
		}
		// south
		else if (traffic_flow == 1) {
			start = start + 1;
			end = end - 1;
		}
		// east
		else if (traffic_flow == 2) {
			start = start - ROWS;
			end = end + ROWS;
		}
		// west
		else if (traffic_flow == 3) {
			start = start + ROWS;
			end = end - ROWS;
		}

		// run the LCP algorithm
		std::cout << "\nFinding least congested path from " << start << " to " << end << "... \n";
		calculateLCP(start, end, adj_list);

		// remove first road from the list and advance root
		Road<V>* temporary = root;
		root = root->getNextRoad();
		delete temporary;
	}
}


template<class V>
void ReactiveRouting<V>::calculateLCP(const V& s, const V& t, std::vector<Intersection<V>*> al) {

	std::vector<Intersection<V>*> adj_list = al;
	bool visited[no_intersections];						//array of boolean values... visited or not
	float segment_congestion[no_intersections];			//array of congestion values from sources (rows) to destinations (columns)
	int least_congested_intrsctn;
	bool adjIntersectionsRemain;
	std::vector<int> pathToDest[no_intersections];		//array of vectors for various paths
	int mark;

	for (int k = 0; k < no_intersections; k++) {
		visited[k] = false;
		segment_congestion[k] = inf;
	}

	visited[s] = true;
	segment_congestion[s] = 0.0;
	least_congested_intrsctn = s;

	while (least_congested_intrsctn != t) {

		adjIntersectionsRemain = true;

		while (adjIntersectionsRemain) {
			int nextAdjIntersection = getNextAdjIntersection(least_congested_intrsctn, adj_list);
			float nextAdjWeight = getNextAdjWeight(least_congested_intrsctn, adj_list, adjIntersectionsRemain);
			//place weight in segment_congestion[] if less than current
			if ((segment_congestion[least_congested_intrsctn] + nextAdjWeight < segment_congestion[nextAdjIntersection])
				&& (!visited[nextAdjIntersection])) {
				segment_congestion[nextAdjIntersection] = segment_congestion[least_congested_intrsctn] + nextAdjWeight;
				//update path
				pathToDest[nextAdjIntersection] = pathToDest[least_congested_intrsctn];
				pathToDest[nextAdjIntersection].push_back(nextAdjIntersection);
			}
		}
		//mark least congested unvisited intersection in segment_congestion[]
		mark = findLeastCongestedIntersection(visited, segment_congestion);
		visited[mark] = true;
		least_congested_intrsctn = mark;
	}
	std::cout << "\nLeast congestion from " << s << " to " << t << ": " << segment_congestion[t] << std::endl;

	// add source to beginning of path
	pathToDest[t].insert(pathToDest[t].begin(), s);
	// print path
	std::cout << "Path is: ";
	for (int j = 0; j < pathToDest[t].size(); j++) {
		if (j == pathToDest[t].size() - 1) std::cout << pathToDest[t][j] << std::endl;
		else std::cout << pathToDest[t][j] << " --> ";
	}
}


template<class V>
float ReactiveRouting<V>::calculateCF(const int& nc, const float& ls, const float& v) {
	float cf;
	cf = (nc / (MAX_NUM_CARS * ls)) * (1 - (v / SPEED_LIMIT));
	return cf;
}

/*
// alternate congestion calculation
template<class V>
float ReactiveRouting<V>::calculateCF(const float& v) {
	float cf;
	cf = 1 - (v / SPEED_LIMIT);
	return cf;
}
*/

template<class V>
void ReactiveRouting<V>::printAdjacencyList(const std::vector<Intersection<V>*>& al) const {
	std::cout << std::endl << "Adjacency list..." << std::endl;
	for (Intersection<V>* Intersec : al) {
		// print all neighboring vertices of given vertex
		Intersection<V>* curr = Intersec;
		std::cout << curr->getIntersectionValue(); //print Map Intersection
		curr = curr->getNextIntersection();
		// don't print dummy intersection at the end
		while (curr->getNextIntersection() != nullptr) {
			std::cout << " --> [" << curr->getIntersectionValue() << ", C(" << std::setprecision(4) << curr->getIntersectionCongestion() << ")]"; //print adjacent Intersections to Map Intersection
			curr = curr->getNextIntersection();
		}
		std::cout << std::endl;
	}
}

template<class V>
void ReactiveRouting<V>::printCongestedRoads(Road<V>* cr) const {
	std::cout << "\nCongested road segments: \n";
	Road<V>* curr = cr;
	while (curr != nullptr) {
		std::cout << curr->getName() << " from " << curr->getSrc() << " to " << curr->getDst() << std::endl;
		curr = curr->getNextRoad();
	}
}

template<class V>
int ReactiveRouting<V>::getNextAdjIntersection(int lwi, const std::vector<Intersection<V>*>& al) const {
	Intersection<V>* curr = al.at(lwi);
	int result = curr->getNextIntersection()->getIntersectionValue();
	return result;
}

template<class V>
float ReactiveRouting<V>::getNextAdjWeight(int lwi, std::vector<Intersection<V>*>& al, bool& air) {
	Intersection<V>* root = al.at(lwi);
	Intersection<V>* curr = root;
	Intersection<V>* dummy = nullptr;
	Intersection<V>* temp = root->getNextIntersection();

	float result = temp->getIntersectionCongestion();

	while (curr->getNextIntersection() != nullptr) curr = curr->getNextIntersection();
	root->setNextIntersection(temp->getNextIntersection());
	curr->setNextIntersection(temp);
	temp->setNextIntersection(nullptr);

	// look for dummy node, mark "air" false and move dummy node to the end if found
	if (root->getNextIntersection()->getIntersectionValue() == inf) {
		air = false;
		curr = curr->getNextIntersection();
		// hold the dummy node
		dummy = root->getNextIntersection();
		root->setNextIntersection(dummy->getNextIntersection());
		curr->setNextIntersection(dummy);
		dummy->setNextIntersection(nullptr);
	}

	return result;
}

template<class V>
int ReactiveRouting<V>::findLeastCongestedIntersection(bool visited[], float segment_congestion[]) {
	float min = inf;
	int lci;
	for (int i = 0; i < no_intersections; i++) {
		if (!visited[i] && segment_congestion[i] <= min) {
			min = segment_congestion[i];
			lci = i;
		}
		//std::cout << "min: " << lci << std::endl;
	}
	return lci;
}

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