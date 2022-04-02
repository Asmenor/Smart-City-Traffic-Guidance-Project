#ifndef _REACTIVE_CLASS
#define _REACTIVE_CLASS

#include <iostream>
#include <string>
#include "Map.h"
#include "DataGenerator.h"

template <class V>
class ReactiveRouting {
    
	Map<int> manhattan;

public:
    ReactiveRouting(std::string&);
	int findLeastCongestedIntersection(bool[], float[]);
	void calculateSP(const V&, const V&);
	void printAllRoads() const;
	void printAdjacencyMatrix() const;
	void printAdjacencyList(const std::vector<Intersection<V>*>&) const;
	float calculateCF(const int& c, const float& l, const float& v);
	int getNextAdjIntersection(int, const std::vector<Intersection<V>*>&) const;
	float getNextAdjWeight(int, std::vector<Intersection<V>*>&, bool&);
	void generateNewMap();

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
void ReactiveRouting<V>::calculateSP(const V& s, const V& t) {

	bool visited[no_intersections];				//array of boolean values... visited or not
	float distance[no_intersections];			//array of distances, which are congestion in this case
	float** adj_matrix = manhattan.getAdjacencyMatrix();
	std::vector<Intersection<V>*> adj_list;
	std::vector<Road<V>*> Roads = manhattan.getRoads();
	int least_congested_intrsctn;
	bool adjIntersectionsRemain;
	std::vector<int> pathToDest[no_intersections];	//array of vectors for various paths

	// update adj_matrix from Roads
	for (auto road : Roads) {
		V src = road->getSrc();
		V dst = road->getDst();
		float congestion = calculateCF(road->getNumCars(), road->getLength(), road->getAvgSpeed());

		adj_matrix[src][dst] = congestion;
	}

	// update adj_list from adj_matrix
	for (int i = 0; i < no_intersections; i++) {
		V s = i;
		adj_list.push_back(new Intersection<V>(s));
		for (int j = 0; j < no_intersections; j++)
			if (adj_matrix[i][j] > 0.00 && adj_matrix[i][j] != inf) {
				Intersection<V>* curr = adj_list.at(s);
				while (curr->getNextIntersection() != nullptr) {
					curr = curr->getNextIntersection();
				}
				V d = j;
				float c = adj_matrix[i][j];
				curr->setNextIntersection(new Intersection<V>(d, c));
			}
	}

	// print adj_list
	printAdjacencyList(adj_list);

	// calculate distance (congestion)
	for (int k = 0; k < no_intersections; k++) {
		visited[k] = false;
		distance[k] = inf;
	}

	visited[s] = true;
	distance[s] = 0.0;
	least_congested_intrsctn = s;

	//update path at source; all paths originate from s
	pathToDest[s].push_back(s);

	while (least_congested_intrsctn != t) {
		int marked = inf;
		adjIntersectionsRemain = true;

		while (adjIntersectionsRemain) {
			int nextAdjIntersection = getNextAdjIntersection(least_congested_intrsctn, adj_list);
			float nextAdjWeight = getNextAdjWeight(least_congested_intrsctn, adj_list, adjIntersectionsRemain);
			//place weight in distance[] if less than current
			if ((distance[least_congested_intrsctn] + nextAdjWeight < distance[nextAdjIntersection])
				&& (!visited[nextAdjIntersection])) {
				distance[nextAdjIntersection] = distance[least_congested_intrsctn] + nextAdjWeight;
				//update path
				pathToDest[nextAdjIntersection] = pathToDest[least_congested_intrsctn];
				pathToDest[nextAdjIntersection].push_back(nextAdjIntersection);
			}
			//mark least congested unvisited intersection in distance[]
			marked = findLeastCongestedIntersection(visited, distance);
		}
		visited[marked] = true;
		least_congested_intrsctn = marked;
	}
	std::cout << "\nLeast congested path from " << s << " to " << t << ": " << distance[t] << std::endl;

	std::cout << "Path is ";
	for (int j = 0; j < pathToDest[t].size(); j++) {
		std::cout << " --> " << pathToDest[t][j];
	}
	std::cout << std::endl;
}

template<class V>
float ReactiveRouting<V>::calculateCF(const int& c, const float& l, const float& v) {
	float cf;
	cf = (c / (352 * l)) / v;
	return cf;
}

template<class V>
void ReactiveRouting<V>::printAdjacencyList(const std::vector<Intersection<V>*>& al) const {
	std::cout << std::endl << "Adjacency list..." << std::endl;
	for (Intersection<V>* Intersec : al) {
		// print all neighboring vertices of given vertex
		Intersection<V>* curr = Intersec;
		std::cout << curr->getIntersectionValue(); //print Map Intersection
		curr = curr->getNextIntersection();
		while (curr != nullptr) {
			std::cout << " --> [" << curr->getIntersectionValue() << ",C(" << std::setprecision(4) << curr->getIntersectionCongestion() << ")]"; //print adjacent Intersections to Map Intersection
			curr = curr->getNextIntersection(); //move to next adjacent Intersection
		}
		std::cout << std::endl;
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
	Intersection<V>* temp = root->getNextIntersection();

	float result = temp->getIntersectionCongestion();

	root->setNextIntersection(temp->getNextIntersection());
	delete temp;

	if (root->getNextIntersection() == nullptr) air = false;

	return result;
}

template<class V>
int ReactiveRouting<V>::findLeastCongestedIntersection(bool visited[], float distance[]) {
	int min = inf, lci;
	for (int i = 0; i < no_intersections; i++) {
		if (!visited[i] && distance[i] <= min) {
			min = distance[i];
			lci = i;
		}
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