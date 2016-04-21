/*
//  hash_stats.cpp
//  
//
//  Created by Gregory O'Marah on 4/21/16.
//
	program measures the performance of various sized hash tables by iterating over each one with random number insertions into hash table.  Records successful insertions count, while Iterates to 100 collisions, per each table.  outputs results via TUI
*/

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// define constant numbers used
const int tblSize = 7;
const int arrMax = 30;
const int randNumMax = 100;

// begin main
int main()
{
    // define and initialize array of tables to be tested
	int aTable[tblSize] = { 7, 11, 13, 17, 19, 23, 29 };
	int insertCount[tblSize] = { 0 };
	double avgInsert[tblSize] = { 0.0 };
	int hashValue = 0;
	int keyValue = 0;
	srand(unsigned int(time(NULL))); // seed random number
	for (int i = 0; i < tblSize; ++i) // execute test per each table as required
	{
		int myArray[arrMax] = { NULL }; // define and initialize empty array for hash table
		int tableSize = aTable[i]; // define tablesize per iteration of hash test
		int collision = 0; // initialize collision count
		int insertion = 0; // initialize insertion count
		do // execute hash table insertion until first collision (100 iterations)
		{
			hashValue = ((unsigned int)rand() % randNumMax) + 1; // generate random number btw 1-100
			keyValue = hashValue % tableSize; // generate hash key from number based on table size h(k) = k%Ts
			if (myArray[keyValue] != NULL) // determine if space to insert is free or occupied
			{
				collision++; // if occupied we have collision incremented
				for (int k = 0; k < arrMax; ++k)
				{
					myArray[k] = NULL; // if collision, array is emptied and init. for next test iteration
				}
			}
			else
			{
				insertion++; // if successful insertion, insertion count is incremented
				myArray[keyValue] = hashValue; // insert hash value into array
			}
		} while (collision < 100); // while loop continues until 100 collisions are recorded
		insertCount[i] = (double)insertion; // count of insertions per table size is stored into an array
		avgInsert[i] = (double)insertCount[i] / randNumMax; // calculate and store in and array, the average insertions
	}
	cout << "Table Size\tAvg Inserts Before Collision\n"; // output results
	for (int i = 0; i < tblSize; ++i)
	{
		cout << "\n" << setw(6) << aTable[i] << "\t" << setw(24) << fixed << setprecision(1) << avgInsert[i] << endl;
	}
	
}
