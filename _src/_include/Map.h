#ifndef _Map
#define _Map

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "Road.h"
#include "Intersection.h"
#include "Split.h"
#include <iomanip>
//for pareto random variables
#include <boost/random.hpp>
#include <boost/range/irange.hpp>


const int inf = 0.0;
const int ROWS = 20;
const int COLS = 5;
const int no_intersections = ROWS * COLS;  //remove and make dynamic

template<class V>
class Map
{
	std::vector<Intersection<V>*> adjListV;
	std::vector<Road<V>*> RoadV;
	float **adj_matrix; //no_Intersections][no_Intersections];

public:
	//Constructor (populates Map)
	Map();
	Map(std::string&);
	void printAdjList() const;
	void printAdjMatrix(bool) const;
	void printRoadMap() const;
	float getExponential(int, float);
	float** getAdjacencyMatrix() const;
};

template<class V>
Map<V>::Map() {
	std::cout << "Map obj created...\n";
}

template<class V>
Map<V>::Map(std::string &f) {
	std::cout << "Loading data file...\n";
	V s = 0;
	adjListV.push_back(new Intersection<V>(s)); //dummy intersection

	//for Pareto Random Variable
	boost::random::mt19937 rng(time(0));
    boost::random::exponential_distribution<> dist(1.0);
    float x_m = 1;
	
	/*Init Adjacency Matrix*/
	//init adj_matrix, adj = 0, all others at inf
	
	adj_matrix = new float*[no_intersections];

	for(int i=0;i<no_intersections;i++){
		adj_matrix[i] = new float[no_intersections];
	}

	for (int i = 0; i < no_intersections; i++)
		for (int j = 0; j < no_intersections; j++){
			//std::cout << i << " " << j << "\n";
			adj_matrix[i][j] = 0.0;
		}
	/**/

	//read <city>.csv file and load road information
	//https://www.new-york-city-map.com/manhattan.htm
	std::ifstream dataFile(f);
	std::string line;
	std::getline (dataFile, line); //ignore header
	if ( dataFile.is_open() ) {
		while ( dataFile ) {
			std::getline (dataFile, line);

			bool IntersectionExists = false;
			std::string name = split(line,',',1,true);
			V src = split(line,',',2);
			V dest = split(line,',',3);
			
			
			//Add Road
			RoadV.push_back(new Road<V>(name, src, dest, static_cast<int>(x_m * getExponential(20, dist(rng))),20,3));
			//end Add Road

			float congestion = 0.0;//= RoadV[RoadV.size - 1].getCongestion();
			std::cout << std::fixed << "\nadding: " << src << "----(" << congestion << ")----" << dest << std::endl;

			/*Add congestion value to adj matrix*/
			adj_matrix[src][dest] = congestion;


			if (! adjListV.empty()) {
				for (Intersection<V> *Intersection : adjListV) {
					if (src == Intersection->getIntersectionValue()) {
						IntersectionExists = true;
						break;
					}
				}
			}

			std::cout << src << (IntersectionExists ? " exists" : " does not exist") << std::endl;

			if (IntersectionExists) {
				std::cout << "updating...";
				//Intersection at the end of list connected to vector |  Intersection  |->... |  Intersection  |->nullptr
				Intersection<V> *curr = adjListV.at(src);
				while (curr->getNextIntersection() != nullptr)
					curr = curr->getNextIntersection();

				curr->setNextIntersection(new Intersection<V>(dest, congestion));
				std::cout << "--> "<< dest << " added." << std::endl;
			}
			else {
				std::cout << "adding...";
				//add Intersection to vector |  Intersection  |->nullptr
				adjListV.push_back(new Intersection<V>(src));
				
				//add associated destination to the Intersection |  Intersection  |->|  Intersection  |->nullptr
				Intersection<V> *curr = adjListV.at(src);
				curr->setNextIntersection(new Intersection<V>(dest, congestion));
				std::cout << "new Intersection and destination added." << std::endl;
			}
		}
	}
	else{
		std::cout << "\nData file '" << f << "', not found.\n";
	}
}

// print adjacency list representation of Map
template<class V>
void Map<V>::printAdjList() const {
	std::cout << std::endl << "Adjacency list..." << std::endl;
	for (Intersection<V> *Intersec : adjListV) {
		// print all neighboring vertices of given vertex
		Intersection<V> *curr = Intersec;
		std::cout << curr->getIntersectionValue(); //print Map Intersection
		curr = curr->getNextIntersection();
		while (curr != nullptr){
			std::cout << " --> [" << curr->getIntersectionValue() << ",C(" << curr->getIntersectionCongestion() << ")]"; //print adjacent Intersections to Map Intersection
			curr = curr->getNextIntersection(); //move to next adjacent Intersection
		}
		std::cout << std::endl;
	}
}

// print adjacency list representation of Map
template<class V>
void Map<V>::printAdjMatrix(bool print_head) const {
	int inter;
	if(print_head)
		inter = 10;
	else
		inter = no_intersections;

	std::cout << std::endl << "Adjacency matrix...(printing head=" << (print_head ? "true" : "false") << ")\n";
	std::cout << "\t";
	for (int i = 0; i < inter; i++) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	for (int i = 0; i < inter; i++) {
		std::cout << i << "\t";
		for (int j = 0; j < inter; j++) {
			if (adj_matrix[i][j] == inf) std::cout << static_cast<unsigned char>(236) << "\t";
			else std::cout << std::setprecision(2) << adj_matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
		
}

template<class V>
float Map<V>::getExponential(int n, float x)
{
    float sum = 1.0;
 
    for (int i = n - 1; i > 0; --i )
        sum = 1 + x * sum / i;
 
    return sum;
}

template<class V>
void Map<V>::printRoadMap() const{
	std::cout << "Roads:\n";
	for( auto x : RoadV){
		std::cout << x->getName() << " " << x->getSrc() << " "  << x->getDst() << " "  << x->getCongestion() << "\n" ;
	}
}

template<class V>
float** Map<V>::getAdjacencyMatrix() const{
	return adj_matrix;
}

#endif