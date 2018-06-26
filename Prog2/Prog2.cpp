#include <iostream>

using namespace std;

int main() 
{
	int board[10][10] = { 0 };
	int randomXSpot = 0;
	int randomYSpot = 0;
	int guessX = 0;
	int guessY = 0;

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

	//ask user for a spot
	cout << "Enter shot row and column (1-10)" << endl;
	cout << "Row: ";
	cin >> guessX;
	while (guessX < 1 || guessX > 10)
	{
		cout << endl << "Row must be between 1 and 10. Please enter another row: ";
		cin >> guessX;
		cout << endl;
	}	
	cout << endl << "Column: ";
	cin >> guessY;
	while (guessY < 1 || guessY > 10)
	{
		cout << endl << "Column must be between 1 and 10. Please enter another Column: ";
		cin >> guessY;
		cout << endl;
	}
	cout << endl;


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