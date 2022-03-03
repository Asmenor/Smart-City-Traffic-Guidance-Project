#ifndef _PROACTIVE_CLASS
#define _PROACTIVE_CLASS

#include <iostream>
#include <string>
#include "Map.h"


template <class V>
class ProactiveRouting {
    
	Map<int> manhattan;

public:
    ProactiveRouting(std::string&);
    void printAllRoads() const;
	void printAdjacencyMatrix() const;
	void printAdjacencyList() const;
    void calculateDijkstrasSP(const V&);
	int findSmallestUnvisitedIntersection(bool[], float[]);

};


template<class V>
ProactiveRouting<V>::ProactiveRouting(std::string &f){
    //load f and create Map
    manhattan = Map<V>(f);
}

template<class V>
void ProactiveRouting<V>::printAllRoads() const{
    //load f and create Map
    manhattan.printRoads();
}

template<class V>
void ProactiveRouting<V>::printAdjacencyMatrix() const{
    //load f and create Map
    manhattan.printAdjMatrix(true);
}

template<class V>
void ProactiveRouting<V>::printAdjacencyList() const{
    //load f and create Map
    manhattan.printAdjList();
}

template<class V>
void ProactiveRouting<V>::calculateDijkstrasSP(const V& u) {
	/* djikstras algorithm adapted from
	https://www.includehelp.com/cpp-tutorial/dijkstras-algorithm.aspx
	*/
    
	bool visited[no_intersections];
	float distance[no_intersections];
	float **adj_matrix = manhattan.getAdjacencyMatrix();
	std::vector<Road<V>*> adj_list = manhattan.getAdjacencyList();

	//init adj_matrix, adj = 0, all others at inf
	/*
	for (int i = 0; i < no_Intersections; i++)
		for (int j = 0; j < no_Intersections; j++)
			if (i == j) adj_matrix[i][j] = 0;
			else adj_matrix[i][j] = inf;
	
	//populate adj_matrix from adjListV
	if (!adjListV.empty()) {
		for (Intersection<V> *Intersec : adjListV) {
			Intersection<V> *curr = Intersec;

			while(curr->getNextIntersection() != nullptr) {
				adj_matrix[Intersec->getIntersectionValue()][curr->getNextIntersection()->getIntersectionValue()] = curr->getNextIntersection()->getIntersectionCongestion();
				curr = curr->getNextIntersection();
			}
		}
	}
	*/
	//manhattan.printAdjMatrix(true); //true; prints 10 rows only

	// calculate distance using djikstra's
	//u's distance to itself = 0
	for (int k = 0; k < no_intersections; k++) {
		visited[k] = false;
		distance[k] = inf;
	}
	distance[u] = 0;

	for (int count = 0; count < no_intersections; count++){
		int v = findSmallestUnvisitedIntersection(visited, distance);		//v is to be added next
		visited[v] = true;											//add v to visited Intersections
		for (int i = 0; i < no_intersections; i++){
			/*Update dist[v] if not in Dset and their is a path from src to v through u that has distance minimum than current value of dist[v]*/
		
			if (!visited[i] && adj_matrix[v][i] != inf && distance[v] != inf)
				if(distance[v] + adj_matrix[v][i] < distance[i])
					distance[i] = distance[v] + adj_matrix[v][i];
		}
	}

	std::cout << "Distances:" << std::endl;
	for (int i = 0; i < no_intersections; i++) {
		if (distance[i] == inf) std::cout << u << "--->" << i << " with distance " << static_cast<unsigned char>(236) << std::endl;
		else std::cout << u << "--->" << i << " with distance " << distance[i] << std::endl;
	}

}

template<class V>
int ProactiveRouting<V>::findSmallestUnvisitedIntersection(bool visited[], float distance[]) {
		int min = inf, smallest_congestion_Intersection;
		for (int i = 0; i < no_intersections; i++){
			if (!visited[i] && distance[i] <= min){
				min = distance[i];
				smallest_congestion_Intersection = i;
			}
		}
		return smallest_congestion_Intersection;
}




#endif