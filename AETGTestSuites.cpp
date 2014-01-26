/* AETGTestSuites.cpp : Defines the entry point for the console application.
	*This code will fetch the Factors and Levels
	*It will generate a single test suite, each test case will be one of 50 candidates and the best will be selected.
	*It will run 100 times for each input received and report the average size and execution time
	*Mixed input is not implemented, every factor will have the same number of levels
	*Steps:
		*Fetch Input for Factors and Levels
		*Generate 50 test case candidates and pick the ideal one for each case then generate the suite
		*Run that 100 times
*/

#include "stdafx.h"

using namespace std;

void fetchInput(int &factor, int &level);
void generateAllTouples(int factor,int level,int** touplesTable);
int** generateTestSuite(int factor, int level,int** touplesTable);
int* generateBestSuite(int factor,int level);

//Test Suite Array sizes until I optimize it.
const int ARRAY_SIZE = 20;

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
	*
	*Then it will create a 2 Dimensional array of every possible Touple and return it
	*With size of (N X 2)
*/
void generateAllTouples(int factor,int level,int** touplesTable)
{
	//Create a 2 Dimensional Pointer array that will hold indexes for each Level in a factor
	int** indexesTable = new int*[factor];
	for (int s=0; s<factor; s++)
		indexesTable[s] = new int[level];

	for (int i=0; i<factor; i++)
	{
		for (int s=0; s<level; s++)
		{
			indexesTable[i][s] = s+(i*3);
		}
	}
	//Now we will generate all possible 2-way pairings and assign them to the touplesTable array
	for (int i=0; i<factor-1; i++) //Step through each factor except the final one
	{
		for (int s=0; s<level; s++) //Step through each level in that factor
		{
			for (int j=0; j<level*(factor-(i+1)); j++) //Step through each level in the factors to the right of the current level
			{
				
			}
		}
	}
	delete [] indexesTable;
}

/*
	* Given Factor and level this generates One Test Suite
	* And returns a pointer to it
*/
int** generateTestSuite(int factor, int level, int** touplesTable)
{
	int RNGValue;
	//Initialize a two dimensional pointer array to hold our suite
	int** testSuite = new int*[ARRAY_SIZE];
	for (int s=0; s < 20; s++)
		testSuite[s] = new int[ARRAY_SIZE];

	//Single Test Case:
		//1. Pick a Factor at random
		//2. Pick another random Factor, choose a level that will cover the most pairs and break a tie with random decision
		//3. Continue until you have selcted all factors
	//If the picking of every factor's level generates no new covered pairs you are done.
	RNGValue = rand() % 10 + 1;

	return testSuite;
}

/*
	*Given Factor and Level this will generate 50 Test Suites
	*And return the smallest one.
*/
int* generateBestSuite(int factor,int level)
{
	//Maximum suite will be assumed to be 20 x 20 for now
	//TODO: Optimize array sizes
	
	int** bestSuite = new int*[ARRAY_SIZE]; //The Best Suite we have that will be returned
	for (int s=0; s<ARRAY_SIZE; s++)
		bestSuite[s] = new int[ARRAY_SIZE];

	//Create a 2 Dimensional Pointer array that will hold our touples
	int toupleArraySize = 0;
	int coverageValue = 2; //Two-way coverage for now
	
	//Initialize touple Array Size
	for (int i=1; i < factor; i++)
		toupleArraySize+= ((factor-i)*level*level);

	cout << endl << "Tuple Array Size of : " << toupleArraySize;
	
	int** touplesTable = new int*[toupleArraySize];
	for (int s=0; s<toupleArraySize; s++)
		touplesTable[s] = new int[coverageValue];

	generateAllTouples(factor, level, touplesTable);

	bestSuite = generateTestSuite(factor, level, touplesTable);

	delete [] touplesTable;
	return *bestSuite;
}

void main(int argc, _TCHAR* argv[])
{
	int* bestSuite;
	int factor,level,dummy;
	fetchInput(factor,level);

	srand(time(NULL)); //Seed our RNG
	cout << rand();

	//for (int i=0; i < 100; i++) //We will run our script 100 times to get statistics
	//{
		bestSuite = generateBestSuite(factor, level);
		//Math things to calculate time taken and average size
	//}
	delete [] bestSuite;
	cin >> dummy; //Pause the script so I can read output
}