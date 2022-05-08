#ifndef _DataGenerator
#define _DataGenerator
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <sstream>
#include "Road.h"				//changed path here

using namespace std;

struct Data {
	string streetName;
	int from;
	int to;
	int avgSpeed;
	int numCars;
	float segLen;
};

template <class V>
class DataGenerator {


public:
	bool readPreviousData(string fileName);
	bool writeNewData(string fileName);
	void assignNewData(
		int avgSpdMin,
		int avgSpdMax,
		int minCar,
		int maxCar);

	//vector<Data> getData();
	vector<Road<V>> getData();

private:
	//vector<Data> vect;
	vector<Road<V>> vect;

	int RandBetweenInt(int min, int max)
	{
		return min + rand() % (max - min + 1);
	}
	float RandBetweenFloat(float min, float max)
	{
		float test = min + (max - min) * rand() / (float)RAND_MAX;
		return test;
	}

	float CF_max = 0.0f;
	float CF_min = 0.0f;

};

template <class V>
vector<Road<V>> DataGenerator<V>::getData()
{
	return vect;
}

template <class V>
bool DataGenerator<V>::readPreviousData(string fileName) {
	string line;
	ifstream myfile("_include/_data/" + fileName);

	Road<int> dt;
	//Data dt;

	if (myfile.is_open())
	{
		getline(myfile, line); // skips the header row
		while (getline(myfile, line))
		{
			vector<string> tokens;
			stringstream s_stream(line);
			while (s_stream.good()) {
				string substr;
				getline(s_stream, substr, ','); //gets the first string delimited by comma
				tokens.push_back(substr);
			}
			dt.setName(tokens[0]);
			dt.setSrcDst(stoi(tokens[1]),stoi(tokens[2]));

			//dt.avg_speed = stof(tokens[3]);
			//dt.no_of_cars = stoi(tokens[4]);
			dt.setAvgSpeed(stof(tokens[3]));
			dt.setNumCars(stoi(tokens[4]));

			dt.setLength(stof(tokens[5]));

			dt.setSpeedLimit(stoi(tokens[6]));
			dt.setCongestion(stof(tokens[7]));

			vect.push_back(dt);
		}
		myfile.close();
		return true;
	}

	else cout << "Unable to open file!" << endl;

	return false;
}

template <class V>
void DataGenerator<V>::assignNewData(int avgSpdMin, int avgSpdMax, int minCar, int maxCar)
{
	srand(time(NULL));
	// Generating new data on dynamic parameters
	for (int i = 0; i < vect.size(); i++)
	{
		//vect[i].avg_speed = RandBetweenInt(avgSpdMin, avgSpdMax);
		//vect[i].no_of_cars = RandBetweenInt(minCar, maxCar);
		vect[i].setAvgSpeed(RandBetweenInt(avgSpdMin, avgSpdMax));
		vect[i].setNumCars(RandBetweenInt(minCar, maxCar));

		float F1 = vect[i].getNumCars() / (vect[i].getLength() * 377);	//get method for no_of_cars substituted

		float F2 = vect[i].getAvgSpeed() / vect[i].getSpeedLimit();
		float CF = F1 / F2;

		// From here after needs to be discussed.

		float CF_max = vect[i].getSpeedLimit() / 5.0f;
		float CF_min = 0.0f;

		vect[i].setCongestion((CF-CF_min)/(CF_max-CF_min));

	}
	return;
}

template <class V>
bool DataGenerator<V>::writeNewData(string fileName) {
	string line;
	ofstream myfile("_include/_data/" + fileName);

	if (myfile.is_open())
	{
		myfile << "street_name,from_junc,to_junc,avg_speed,num_cars,seg_len,spd_limit,congestion" << endl;

		for (int i = 0; i < vect.size(); i++)
		{
			myfile << vect[i].getName() << ",";
			myfile << vect[i].getSrc() << ",";
			myfile << vect[i].getDst() << ",";
			myfile << vect[i].getAvgSpeed() << ",";
			myfile << vect[i].getNumCars() << ",";
			myfile << vect[i].getLength() << ",";
			myfile << vect[i].getSpeedLimit() << ",";
			myfile << vect[i].getCongestion() << endl;
		}
		myfile.close();
		
		return true;
	}

	else cout << "Unable to open file!" << endl;

	return false;
}






#endif