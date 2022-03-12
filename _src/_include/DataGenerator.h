#ifndef _DataGenerator
#define _DataGenerator
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include<sstream>
using namespace std;

struct Data {
	string streetName;
	int from;
	int to;
	int avgSpeed;
	int numCars;
	float segLen;
};

class DataGenerator {


public:
	bool readPreviousData(string fileName);
	bool writeNewData(string fileName);
	void assignNewData(
		int avgSpdMin,
		int avgSpdMax,
		int minCar,
		int maxCar,
		float minSegLen,
		float maxSegLen);

	vector<Data> getData();

private:
	vector<Data> vect;


	int RandBetweenInt(int min, int max)
	{
		return min + rand() % (max - min + 1);
	}
	float RandBetweenFloat(float min, float max)
	{
		float test = min + (max - min) * rand() / (float)RAND_MAX;
		return test;
	}
};

vector<Data> DataGenerator::getData()
{
	return vect;
}

bool DataGenerator::readPreviousData(string fileName) {
	string line;
	ifstream myfile("_src/_include/_data/" + fileName);

	Data dt;

	if (myfile.is_open())
	{
		getline(myfile, line); // skips the header row
		while (getline(myfile, line))
		{
			vector<string> tokens;
			stringstream s_stream(line);
			while (s_stream.good()) {
				string substr;
				getline(s_stream, substr, ','); //get first string delimited by comma
				tokens.push_back(substr);
			}
			dt.streetName = tokens[0];
			dt.from = stoi(tokens[1]);
			dt.to = stoi(tokens[2]);
			dt.avgSpeed = stoi(tokens[3]);
			dt.numCars = stoi(tokens[4]);
			dt.segLen = stof(tokens[5]);
			vect.push_back(dt);
		}
		myfile.close();
		return true;
	}

	else cout << "Unable to open file!" << endl;

	return false;
}

void DataGenerator::assignNewData(int avgSpdMin, int avgSpdMax, int minCar, int maxCar, float minSegLen, float maxSegLen)
{
	srand(time(NULL));
	// Generating new data on dynamic parameters
	for (int i = 0; i < vect.size(); i++)
	{
		vect[i].avgSpeed = RandBetweenInt(avgSpdMin, avgSpdMax);
		vect[i].numCars = RandBetweenInt(minCar, maxCar);
		if (i % 2 == 0)
			vect[i].segLen = RandBetweenFloat(minSegLen, maxSegLen);
		else
			vect[i].segLen = vect[i - 1].segLen;
	}
	return;
}

bool DataGenerator::writeNewData(string fileName) {
	string line;
	ofstream myfile("_src/_include/_data/" + fileName);

	if (myfile.is_open())
	{
		myfile << "street_name,from_junc,to_junc,avg_speed,num_cars,seg_len" << endl;

		for (int i = 0; i < vect.size(); i++)
		{
			myfile << vect[i].streetName << ",";
			myfile << vect[i].from << ",";
			myfile << vect[i].to << ",";
			myfile << vect[i].avgSpeed << ",";
			myfile << vect[i].numCars << ",";
			myfile << vect[i].segLen << endl;
		}
		myfile.close();
		
		return true;
	}

	else cout << "Unable to open file!" << endl;

	return false;
}






#endif