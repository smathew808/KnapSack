#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>



//Name: Sean Mathews
//Class: CS340
//Instructor: Ercal
//Project: KnapSack

using namespace std;

struct item {
	int itemId;
	int itemWeight;//an items weight, the higher the weight, the heavier it is
	int itemValue;//an items value, such as dollars, the higher the value, the more worth that item is
};

class KnapSack{


private:

public:

	//list of items 
	vector<item> itemList;
	vector<item> winnerList;
	

	bool choiceTable[6][7]; // TO BE CHANGED to dynamic array
	int knapsackTable[6][7]; //keeps track of the current values in each cell


	int numberOfItems;
	int maxWeightOfKnapsack;
	//2d vector for the knapsackTable
	//vector<vector<int> > knapsackTable;

	KnapSack();

 void loadInData(string fileName);

 int knapSackAlg(int maxWeight, int numberOfItems, int(&knapsackTable)[6][7], vector<item> &itemlist, bool(&choiceTable)[6][7], vector<item> &winnerList);
 int max(int newValue, int inheritedValue);
};

