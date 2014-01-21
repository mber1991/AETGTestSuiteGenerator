/* AETGTestSuites.cpp : Defines the entry point for the console application.
	*This code will fetch the Factors and Levels, it will then create 50 candidate test suites and select the best fit.
	*It will run 100 times for each input received and report the average size and execution time
	*Mixed input is not implemented, every factor will have the same number of levels
	*Steps:
		*Fetch Input for Factors and Levels
		*Generate 50 test suites and pick the ideal (smallest) one
		*Run that 100 times
*/

#include "stdafx.h"

using namespace std;

void fetchInput(int &factor, int &level);
int* generateTestSuite(int factor, int level);
int* generateBestSuite(int factor,int level);
void generateIndexesTable(int factor,int level,int** indexes);
/*
	* Fetch the number of factors and levels and update integers by reference
	* Visually: A factor is a column, a level is a row
*/
void fetchInput(int &factor, int &level)
{
	cout << "Enter Factors: ";
	cin >> factor;
	cout << "Enter Levels: ";
	cin >> level;
}

/*
	*Generate an indexes table
	*It will create a 2 dimensional array, passed by reference, that holds our indexes
	*Ex: Factor 0 will have 0, 1, 2 Factor 2 will have 3, 4, 5 etc...
	*so array[0] will be {0,1,2}
*/
void generateIndexesTable(int factor,int level,int** indexes)
{
	for (int i=0; i<factor; i++)
	{
		for (int s=0; s<level; s++)
		{
			indexes[i][s] = s+(i*3);
			cout << indexes[i][s] << " ";
		}
		cout << endl;
	}

}
/*
	* Given Factor and level this generates One Test Suite
	* And returns a pointer to it
*/
int* generateTestSuite(int factor, int level)
{
	int testSuite[20][20];
	
	return *testSuite;
}

/*
	*Given Factor and Level this will generate 50 Test Suites
	*And return the smallest one.
*/
int* generateBestSuite(int factor,int level)
{
	//Maximum suite will be assumed to be 20 x 20 for now
	//TODO: Optimize array sizes
	int* allSuites[50]; //Array of pointers to the 50 Suites we generate
	int bestSuite[20][20]; //The Best Suite we have that will be returned
	
	//Create a 2 Dimensional Pointer array that will hold indexes for each Level in a factor
	int** indexesTable = new int*[factor];
	for (int s=0; s<factor; s++)
		indexesTable[s] = new int[level];
	
	generateIndexesTable(factor, level, indexesTable);

	for (int i=0; i < 50; i++)
	{
		allSuites[i] = generateTestSuite(factor, level);
	}

	delete [] indexesTable;
	return *bestSuite;
}

void main(int argc, _TCHAR* argv[])
{
	int* bestSuite;
	int factor,level,dummy;
	fetchInput(factor,level);

	//for (int i=0; i < 100; i++) //We will run our script 100 times to get statistics
	//{
		bestSuite = generateBestSuite(factor, level);

		//Math things to calculate time taken and average size
	//}

	cin >> dummy; //Pause the script so I can read output
}

