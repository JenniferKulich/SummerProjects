#include <iostream>

using namespace std;

int main() 
{
	int board[10][10] = { 0 };
	int randomXSpot = 0;
	int randomYSpot = 0;

	//for loop that will get random spot for all 3 ships
	int i;
	for (i = 1; i < 4; i++)
	{
		//get random spot for ship
		randomXSpot = rand() % 10 + 1;
		randomYSpot = rand() % 10 + 1;

		cout << randomXSpot << endl << randomYSpot << endl;

		//mark random spot of ship
		board[randomXSpot - 1][randomYSpot - 1] = i;
	}


	//check to make sure board spot changes
	/*int n;
	for (i = 0; i < 10; i++)
	{
		for (n = 0; n < 10; n++)
			cout << board[i][n];
		cout << endl;
	}*/




	return 0;
}