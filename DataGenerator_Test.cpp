// DataGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "_include/DataGenerator.h"

int main()
{
	DataGenerator dg;
	if (dg.readPreviousData("manhattan.csv"))
	{
		dg.assignNewData(20, 30, 10, 30, 0.6, 0.8);
		if (!dg.writeNewData("manhattan_test.csv"))
			cout << "Error in writting the file!" << endl;
		else
			cout << "New data generated." << endl;
	}

	return 0;
}
