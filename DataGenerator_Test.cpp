// DataGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "_src/_include/DataGenerator.h"

int main()
{
	DataGenerator<int> dg;
	if (dg.readPreviousData("manhattan_actual.csv"))
	{
		dg.assignNewData(5, 25, 100, 300);
		if (!dg.writeNewData("manhattan_test.csv"))
			cout << "Error in writting the file!" << endl;
		else
			cout << "New data generated." << endl;
	}

	return 0;
}
