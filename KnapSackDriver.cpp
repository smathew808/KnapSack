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
//Project: KnapSack

using namespace std;


int main(){

	KnapSack knapsackGraph;



	int winner; //the final solution in the knapsack alg

	knapsackGraph.loadInData("knapsack.txt");
	winner = knapsackGraph.knapSackAlg(knapsackGraph.maxWeightOfKnapsack, knapsackGraph.numberOfItems, knapsackGraph.knapsackTable, knapsackGraph.itemList, knapsackGraph.choiceTable, knapsackGraph.winnerList);

	cout << "The optimal Knapsack solution has total value  " << winner << endl <<

		 " and involves items{";


	for (int i = 1; i < knapsackGraph.winnerList.size(); i++)
	{
		cout << knapsackGraph.winnerList[i].itemId << ", ";
	}

	cout << "}" << endl;

	system("pause");

	return 0;
}