#include <iostream>
#include <ostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include "KnapSackHeader.h"



//Name: Sean Mathews
//Class: CS340
//Instructor: Ercal
//Project: Knapsack

using namespace std;



KnapSack::KnapSack()
{

}



void KnapSack::loadInData(string fileName) {

	ifstream graphFile; //file object to read in file


	string numberOfItemsString; //string version, will convert to int

	string maxWeightOfKnapsackString;// " "

	string itemWeightString;// " "
	int itemWeightReader;//an items weight, the higher the weight, the heavier it is


	string itemValueString;// " "
	int itemValueReader;//an items value, such as dollars, the higher the value, the more worth that item is

	int itemIdCtr = 1;

	

	graphFile.open(fileName);

	if (graphFile.fail()) {
		cout << "Oops! file couldn't open." << endl;
	}

	
	while (!graphFile.eof())
	{
		getline(graphFile, numberOfItemsString, ' ');
		numberOfItems = stoi(numberOfItemsString); //read in the number of items

		getline(graphFile, maxWeightOfKnapsackString);
		maxWeightOfKnapsack = stoi(maxWeightOfKnapsackString); //read in maxWeight of knapsack
		
	
		itemList.resize(1); //make space for item 0
		
		itemList[0].itemId = 0; //add item 0
		itemList[0].itemValue = 0;
		itemList[0].itemValue = 0;


		for (int i = 1; i < 5; i++)
		{
			itemList.resize(i + 1); //resize array

			getline(graphFile, itemWeightString, ' '); //read in the item weight
			itemWeightReader = stoi(itemWeightString);
			itemList[i].itemWeight = itemWeightReader;

			//knapsackTable[i][0] = itemWeight;

			getline(graphFile, itemValueString);	//read in the item value
			itemValueReader = stoi(itemValueString);
			itemList[i].itemValue = itemValueReader;
			
			//knapsackTable[i][1] = itemValue;

			//knapsackTable[i][2] = itemIdCtr;
			itemList[i].itemId = itemIdCtr; //read in the item number
			itemIdCtr++;
		}
		//fill first column with item ids

		/*for (int i = 0; i < itemList.size(); i++)
		{
			knapsackTable[i][0] = itemList[i].itemId;
		}*/


		//fills bottom row with weights
		/*knapsackTable[5][1] = 0;
		knapsackTable[5][2] = 1;
		knapsackTable[5][3] = 2;
		knapsackTable[5][4] = 3;
		knapsackTable[5][5] = 4;
		knapsackTable[5][6] = 5;
		knapsackTable[5][7] = 6;*/

	}
}

//takes in 2 ints, a newValue is the newValue adds to the 
int KnapSack::max(int newValue, int inheritedValue)
{
	
	return (newValue > inheritedValue) ? newValue : inheritedValue;
}

int KnapSack::knapSackAlg(int maxWeight, int numberOfItems, int(&knapsackTable)[6][7], vector<item> &itemlist, bool(&choiceTable)[6][7], vector<item> &winnerList)
{
	
	//int knapsackTable[n + 1][W + 1];

	// Build table K[][] in bottom up manner

	int rowCounter = 5; //counts how many rows there are
	int columnCounter; //counts how many columns there are

	int winnerListCounter = 0; //to resize the vector when needed

	for (int i = numberOfItems + 1; i > 0; i--) //this handles bottom to top
	{
		columnCounter = 0; //counts how many blocks there are in a row

		for (int w = 0; w <= maxWeight; w++) //this goes from left to right
		{
			

			if (i == 5 || w == 0) //if you are the zero item or at the zero weight, then its gonna be 0 every time. fill the first row and column with 0s
			{
				knapsackTable[i][w] = 0;
			}
			else if (itemList[i].itemWeight <= w) { //if the item i's weight is less than the current weight then compare
											//															//item below currIndex we are at
				//knapsackTable[i][w] = max(itemList[i].itemValue + knapsackTable[i + 1][(w - itemList[i].itemWeight)], knapsackTable[i + 1][w]);
				int diag = itemList[i].itemValue + knapsackTable[i + 1][(w - itemList[i].itemWeight)];
				int vert = knapsackTable[i + 1][w];

				if (diag > vert) {
					knapsackTable[i][w] = diag;
					choiceTable[i][w] = true;
				}
				else {
					knapsackTable[i][w] = vert;
					choiceTable[i][w] = false;
				}

			}
			else //assign current index at [i][w] to the value to the below it; inheirt the value from below
				knapsackTable[i][w] = knapsackTable[i + 1][w];

			columnCounter++;
		}

		rowCounter--;
	}

	//while you are not at the bottomleft corner of the matrix
	/*while ((columnCounter != 0) && rowCounter != 5)
	{
	}*/

	int winnerListIndex = 0;

	for (int i = 1; i < numberOfItems + 1; i++)
	{
		//if the value in the choiceTable is true
		if (choiceTable[i][columnCounter - 1] == true)
		{
			winnerListCounter++; //resize counter
			winnerList.resize(winnerListCounter + 1); //resize winnerList

			winnerList[winnerListCounter] = itemList[i]; //reassigns the item at index i in the itemList to the winnerList at index i

			columnCounter = columnCounter - itemList[i].itemWeight; //reduce the counter
		}

	}

	return knapsackTable[1][6];
	
}
