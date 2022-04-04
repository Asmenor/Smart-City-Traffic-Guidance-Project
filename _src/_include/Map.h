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


const float inf = 100.0;
const int ROWS = 20;
const int COLS = 5;
const int no_intersections = ROWS * COLS;  //remove and make dynamic

template<class V>
class Map
{
	std::vector<Road<V>*> adjListV;
	std::vector<Road<V>*> RoadV;
	float **adj_matrix;

public:
	//Constructor (populates Map)
	Map();
	Map(std::string&);
	bool updateMap();									//updates the map with latest congestion data
	void printAdjList() const;
	void printAdjMatrix(bool) const;
	void printRoads() const;
	float getExponential(int, float);					//used for generating Pareto RV.
	float** getAdjacencyMatrix() const;					//returns a 2D adjacency matrix
	std::vector<Road<V>*> getAdjacencyList() const;		//returns the adjacency list vector
	Road<V>* findRoad(V, V) const;
	std::vector<Road<V>*> getRoads() const;				//returns the roads vector
};

template<class V>
Map<V>::Map() {
	std::cout << "Map obj created...\n";
}

template<class V>
Map<V>::Map(std::string &f) {
	std::cout << "Loading data file...\n";
	V s = 0;
	//adjListV.push_back(new Road<V>()); //dummy intersection

	//for Pareto Random Variable
	boost::random::mt19937 rng(time(0));
    boost::random::exponential_distribution<> dist(1.0);
    float x_m = 1;
	
	/*Init Adjacency Matrix*/
	
	adj_matrix = new float*[no_intersections];

	for(int i=0;i<no_intersections;i++){
		adj_matrix[i] = new float[no_intersections];
	}

	//THIS ALTERED
	for (int i = 0; i < no_intersections; i++) {
		for (int j = 0; j < no_intersections; j++) {
			//std::cout << i << " " << j << "\n";
			if (i == j) adj_matrix[i][j] = 0.0;
			else adj_matrix[i][j] = inf;
		}
	}
	/**/

	//read <city>.csv file and load road information
	//https://www.new-york-city-map.com/manhattan.htm
	std::ifstream dataFile(f.c_str());
	std::string line;
	std::getline (dataFile, line); //ignore header

	

	if ( dataFile.is_open() ) {
		bool RoadExists = false;
		bool uTurn = false;
		float congestion;
		Road<V>* temp;
		Road<V> *curr;
		std::string name;
		V src;
		V dest;
		float avg_speed;
		int no_of_cars;
		float length_segment;
		int sp_limit;
		int no_lanes;
		while ( dataFile ) {
			std::getline (dataFile, line);

			RoadExists = false;
			uTurn = false;
			name = split(line,',',1,true);
			src = split(line,',',2);
			dest = split(line,',',3);
			//added new parameters here
			avg_speed = split(line, ',', 4);
			no_of_cars = split(line, ',', 5);
			//bool indicates a return type of float if true
			length_segment = split(true, line, ',', 6);
			sp_limit = 20;
			no_lanes = 1;

			
			
			/* DEPRECATED?
			RoadV.push_back(new Road<V>(name, src, dest, static_cast<int>(x_m * getExponential(20, dist(rng))),20,3));
			*/

			//Add Road
			RoadV.push_back(new Road<V>(name, src, dest, no_of_cars, length_segment, avg_speed, no_lanes, sp_limit));
			//end


			congestion = RoadV[RoadV.size() - 1]->getCongestion();
			//std::cout << std::fixed << "\nadding: " << src << "----(" << congestion << ")----" << dest << std::endl;
			

			std::cout << std::fixed << "\nadding: " << src << "-->" << dest << std::endl;

			/* DEPRECATED?
			//Add congestion value to adj matrix
			adj_matrix[src][dest] = congestion;
			*/

			// DEPRECATED?
			//populate adjacency list
			if (! adjListV.empty()) {
				for (Road<V> *Rd : adjListV) {
					if (Rd->getDst() == src /*|| src == Rd->getDst()*/) { //check src dst links (check src and destination)
						RoadExists = true;
						temp = Rd;
						break;
					}
				}
			}
			//3-4 is a road in itself AND it is connected to 2-3 and 4-5

			std::cout << name << " [" << src << "," << dest << "]" << (RoadExists ? " exists" : " does not exist") << std::endl;

			if (RoadExists) {
				uTurn = (temp->getDst() == src && temp->getSrc() == dest); //true if road is a u-turn
				if (!uTurn){
					std::cout << "(\"" << temp->getName() << "\" S:" << temp->getSrc() << " D:" << temp->getDst() << ")";
					//Add road at the end of list connected to vector |  Road  |->... |  Road  |->nullptr
					curr = temp;//findRoad(src,dest);

					while (curr->getNextRoad() != nullptr)
						curr = curr->getNextRoad();
					
					curr->setNextRoad(new Road<V>(name, src, dest, no_of_cars, length_segment, avg_speed, no_lanes, sp_limit));
					
					//curr->setNextRoad(new Road<V>(name, src, dest, congestion,20,3));
					std::cout << "--> \""<< name << "\" " << src << " " << dest << " added." << std::endl;
				}
				else{
					std::cout << "----ignoring u-turn\n";
				}
			}
			else {
				std::cout << "(First) \""<< name << "\" " << src << " " << dest << " added." << std::endl;
				//Add road to vector |  Road  |->nullptr
				adjListV.push_back(new Road<V>(name, src, dest, no_of_cars, length_segment, avg_speed, no_lanes, sp_limit));
				
				//add associated destination to the Intersection |  Intersection  |->|  Intersection  |->nullptr
				//Road<V> *curr = adjListV.at(src);
				//curr->setNextIntersection(new Intersection<V>(dest, congestion));
				//std::cout << "new Intersection and destination added." << std::endl;
			

			/* DEPRECATED
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
			*/
			}
			
		}
	}
	else{
		std::cout << "\nData file '" << f << "', not found.\n";
	}
}

template<class V>
bool updateMap(){
	std::cout << "reloading file, updating map";
	return true;
}
// print adjacency list representation of Map
template<class V>
void Map<V>::printAdjList() const {
	std::cout << std::endl << "Adjacency list..." << std::endl;
	Road<V> *curr = nullptr;
	for (Road<V> *Rd : adjListV) {
		// print all neighboring vertices of given vertex
		curr = Rd;
		std::cout << curr->getName() << "[" << curr->getSrc() << "," << curr->getDst() << "]"; //print Road name
		if(curr->getNextRoad() != nullptr){
			curr = curr->getNextRoad();
			while (curr != nullptr){
				std::cout << " --> [\"" << curr->getName() << "\" " << curr->getSrc() << "," << curr->getDst() << " ,C(" << curr->getCongestion() << ")]"; //print adjacent Roads
				curr = curr->getNextRoad(); //move to next adjacent Road
			}
			std::cout << std::endl;
		}
		else
			std::cout << " --> no connections" << std::endl;
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
void Map<V>::printRoads() const{
	std::cout << "Roads:\n";
	for( auto x : RoadV){
		std::cout << x->getName() << " " << x->getSrc() << " "  << x->getDst() << " "  << x->getCongestion() << "\n" ;
	}
}

template<class V>
float** Map<V>::getAdjacencyMatrix() const{
	return adj_matrix;
}

template<class V>
std::vector<Road<V>*> Map<V>::getAdjacencyList() const{
	return adjListV;
}

template<class V>
Road<V>* Map<V>::findRoad(V src, V dst) const{
	for(auto x : adjListV){
		if (x->getSrc() == src && x->getDst() == dst)
			return x;
	}
	return nullptr;
}

template<class V>
std::vector<Road<V>*> Map<V>::getRoads() const {
	return RoadV;
}

#endif