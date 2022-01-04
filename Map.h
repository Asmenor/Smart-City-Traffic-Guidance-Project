#ifndef _Map
#define _Map

#include <iostream>
#include <vector>
#include <algorithm>
#include "Road.h"
#include "Intersection.h"
#include "RoadMapInterface.h"
using namespace std;

const int inf = 1000;
const int no_Intersections = 5;  //remove and make dynamic

template<class V>
class Map : public RoadMapInterface<V>
{
	vector<Intersection<V>*> adjListV;
	int adj_matrix[no_Intersections][no_Intersections];
public:
	//Constructor (populates Map)
	Map(string&);
	void calculateSP(const V&);
	int findSmallestUnvisitedIntersection(bool[], int[]);
	void printAdjList() const;
	void printAdjMatrix() const;
	//complete functions from the interface
};

template<class V>
Map<V>::Map(string &f) {
	//read <city>.dat file and load road information
	// add Roads to the directed Map
	for (auto &Road : Roads)
	{
		bool IntersectionExists = false;
		V src = Road.getSrc();
		V dest = Road.getDst();
		int weight = Road.getWeight();
		cout << "adding: " << src << "----w(" << weight << ")----" << dest << endl;
		

		if (! adjListV.empty()) {
			for (Intersection<V> *Intersection : adjListV) {
				if (src == Intersection->getIntersectionValue()) {
					IntersectionExists = true;
					break;
				}
			}
		}

		cout << src << (IntersectionExists ? " exists" : " does not exist") << endl;

		if (IntersectionExists) {
			//Intersection at the end of list connected to vector |  Intersection  |->... |  Intersection  |->nullptr
			Intersection<V> *curr = adjListV.at(src);
			while (curr->getNextIntersection() != nullptr)
				curr = curr->getNextIntersection();

			curr->setNextIntersection(new Intersection<V>(dest, weight));
			cout << "--> "<< dest << " added." << endl;
		}
		else {
			//add Intersection to vector |  Intersection  |->nullptr
			adjListV.push_back(new Intersection<V>(src));
			
			//add associated destination to the Intersection |  Intersection  |->|  Intersection  |->nullptr
			Intersection<V> *curr = adjListV.at(src);
			curr->setNextIntersection(new Intersection<V>(dest, weight));
			cout << "new Intersection and destination added." << endl;
		}
	}
}

template<class V>
void Map<V>::calculateSP(const V& u) {

	bool visited[no_Intersections];
	int distance[no_Intersections];

	//init adj_matrix, adj = 0, all others at inf
	for (int i = 0; i < no_Intersections; i++)
		for (int j = 0; j < no_Intersections; j++)
			if (i == j) adj_matrix[i][j] = 0;
			else adj_matrix[i][j] = inf;

	//populate adj_matrix from adjListV
	if (!adjListV.empty()) {
		for (Intersection<V> *Intersection : adjListV) {
			Intersection<V> *curr = Intersection;

			while(curr->getNextIntersection() != nullptr) {
				adj_matrix[Intersection->getIntersectionValue()][curr->getNextIntersection()->getIntersectionValue()] = curr->getNextIntersection()->getIntersectionWeight();
				curr = curr->getNextIntersection();
			}
		}
	}

	printAdjMatrix();

	// calculate distance
																	//u's distance to itself = 0
	for (int k = 0; k < no_Intersections; k++) {
		visited[k] = false;
		distance[k] = inf;
	}
	distance[u] = 0;

	for (int count = 0; count < no_Intersections; count++){
		int v = findSmallestUnvisitedIntersection(visited, distance);		//v is to be added next
		visited[v] = true;											//add v to visited Intersections
		for (int i = 0; i < no_Intersections; i++){
			/*Update dist[v] if not in Dset and their is a path from src to v through u that has distance minimum than current value of dist[v]*/
		
			if (!visited[i] && adj_matrix[v][i] != inf && distance[v] != inf)
				if(distance[v] + adj_matrix[v][i] < distance[i])
					distance[i] = distance[v] + adj_matrix[v][i];
		}
	}

	cout << "Distances:" << endl;
	for (int i = 0; i < no_Intersections; i++) {
		if (distance[i] == inf) cout << u << "--->" << i << " with distance " << static_cast<unsigned char>(236) << endl;
		else cout << u << "--->" << i << " with distance " << distance[i] << endl;
	}

}

template<class V>
int Map<V>::findSmallestUnvisitedIntersection(bool visited[], int distance[]) {
		int min = inf, smallest_weight_Intersection;
		for (int i = 0; i < no_Intersections; i++){
			if (!visited[i] && distance[i] <= min){
				min = distance[i];
				smallest_weight_Intersection = i;
			}
		}
		return smallest_weight_Intersection;
}


// print adjacency list representation of Map
template<class V>
void Map<V>::printAdjList() const {
	cout << endl << "Adjacency list..." << endl;
	for (Intersection<V> *Intersection : adjListV) {
		// print all neighboring vertices of given vertex
		Intersection<V> *curr = Intersection;
		cout << curr->getIntersectionValue(); //print Map Intersection
		curr = curr->getNextIntersection();
		while (curr != nullptr){
			cout << " --> [" << curr->getIntersectionValue() << ",w(" << curr->getIntersectionWeight() << ")]"; //print adjacent Intersections to Map Intersection
			curr = curr->getNextIntersection(); //move to next adjacent Intersection
		}
		cout << endl;
	}
}

// print adjacency list representation of Map
template<class V>
void Map<V>::printAdjMatrix() const {
	cout << endl << "Adjacency matrix..." << endl;
	cout << "\t";
	for (int i = 0; i < no_Intersections; i++) {
		cout << i << "\t";
	}
	cout << endl;
	for (int i = 0; i < no_Intersections; i++) {
		cout << i << "\t";
		for (int j = 0; j < no_Intersections; j++) {
			if (adj_matrix[i][j] == inf) cout << static_cast<unsigned char>(236) << "\t";
			else cout << adj_matrix[i][j] << "\t";
		}
		cout << endl;
	}
		
}

#endif