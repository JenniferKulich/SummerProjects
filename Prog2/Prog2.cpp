#include <iostream>

using namespace std;

void askUser(int &guessX, int &guessY);
void directHit(int guessX, int guessY, int &numShipsHit, int board[][10]);
void hitByOne(int guessX, int guessY, int &numShipsHit, int board[][10]);
void missedByTwo(int guessX, int guessY, int board[][10]);
void changeHitShip(int hitShip, int board[][10]);

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

	int numShipsHit = 0;

	while (numShipsHit < 3)
	{
		//call function to ask user for guess of spot
		askUser(guessX, guessY);
		
		//change the row and column so compatable with array
		guessX = guessX - 1;
		guessY = guessY - 1;

		//check if direct hit
		directHit(guessX, guessY, numShipsHit, board);
		
		//check if ship hit by one space
		hitByOne(guessX, guessY, numShipsHit, board);

		//check if ship was missed by two spaces
		missedByTwo(guessX, guessY, board);
		
		cout << endl;
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

//function to ask user what their guess is on the ship
void askUser(int &guessX, int &guessY)
{
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

	return;
}


//function to check if the ship was directly hit
void directHit(int guessX, int guessY, int &numShipsHit, int board[][10])
{
	//check to see if spot was a hit
	if (board[guessX][guessY] != 0)
	{
		if (board[guessX][guessY] == 1)
		{
			cout << "Ship 1 was hit directly!" << endl;
			changeHitShip(1, board);
			numShipsHit = numShipsHit + 1;
		}
		else if (board[guessX][guessY] == 2)
		{
			cout << "Ship 2 was hit directly!" << endl;
			changeHitShip(2, board);
			numShipsHit = numShipsHit + 1;
		}
		else
		{
			cout << "Ship 3 was hit directly!" << endl;
			changeHitShip(3, board);
			numShipsHit = numShipsHit + 1;
		}

	}
	return;
}

//function to check if the ship was hit by one spot
void hitByOne(int guessX, int guessY, int &numShipsHit, int board[][10])
{
	if (board[guessX][guessY + 1] != 0 || board[guessX + 1][guessY + 1] != 0 ||
		board[guessX + 1][guessY] != 0 || board[guessX + 1][guessY - 1] != 0 ||
		board[guessX][guessY - 1] != 0 || board[guessX - 1][guessY - 1] != 0 ||
		board[guessX - 1][guessY] != 0 || board[guessX - 1][guessY + 1] != 0)
	{
		if (board[guessX][guessY + 1] != 1 || board[guessX + 1][guessY + 1] != 1 ||
			board[guessX + 1][guessY] != 1 || board[guessX + 1][guessY - 1] != 1 ||
			board[guessX][guessY - 1] != 1 || board[guessX - 1][guessY - 1] != 1 ||
			board[guessX - 1][guessY] != 1 || board[guessX - 1][guessY + 1] != 1)
		{
			numShipsHit = numShipsHit + 1;
			cout << "Hit ship 1!" << endl;
			changeHitShip(1, board);
		}

		else if (board[guessX][guessY + 1] != 2 || board[guessX + 1][guessY + 1] != 2 ||
			board[guessX + 1][guessY] != 2 || board[guessX + 1][guessY - 1] != 2 ||
			board[guessX][guessY - 1] != 2 || board[guessX - 1][guessY - 1] != 2 ||
			board[guessX - 1][guessY] != 2 || board[guessX - 1][guessY + 1] != 2)
		{
			cout << "Hit ship 2!" << endl;
			changeHitShip(2, board);
			numShipsHit = numShipsHit + 1;
		}

		else
		{
			cout << "Hit ship 3!" << endl;
			changeHitShip(3, board);
			numShipsHit = numShipsHit + 1;
		}
	}
	return;
}

//function to check if ship was missed by two spots
void missedByTwo(int guessX, int guessY, int board[][10])
{
	if (board[guessX][guessY - 2] != 0 || board[guessX + 1][guessY - 2] != 0 ||
		board[guessX + 2][guessY - 2] != 0 || board[guessX + 2][guessY - 1] != 0 ||
		board[guessX + 2][guessY] != 0 || board[guessX + 2][guessY + 1] != 0 ||
		board[guessX + 2][guessY + 2] != 0 || board[guessX + 1][guessY + 2] != 0 ||
		board[guessX][guessY + 2] != 0 || board[guessX - 1][guessY + 2] != 0 ||
		board[guessX - 2][guessY + 2] != 0 || board[guessX - 2][guessY + 1] != 0 ||
		board[guessX - 2][guessY] != 0 || board[guessX - 2][guessY - 1] != 0 ||
		board[guessX - 2][guessY - 2] != 0 || board[guessX - 1][guessY - 2] != 0)
	{
		if (board[guessX][guessY - 2] != 1 || board[guessX + 1][guessY - 2] != 1 ||
			board[guessX + 2][guessY - 2] != 1 || board[guessX + 2][guessY - 1] != 1 ||
			board[guessX + 2][guessY] != 1 || board[guessX + 2][guessY + 1] != 1 ||
			board[guessX + 2][guessY + 2] != 1 || board[guessX + 1][guessY + 2] != 1 ||
			board[guessX][guessY + 2] != 1 || board[guessX - 1][guessY + 2] != 1 ||
			board[guessX - 2][guessY + 2] != 1 || board[guessX - 2][guessY + 1] != 1 ||
			board[guessX - 2][guessY] != 1 || board[guessX - 2][guessY - 1] != 1 ||
			board[guessX - 2][guessY - 2] != 1 || board[guessX - 1][guessY - 2] != 1)
			cout << "Near miss ship 1!" << endl;

		else if (board[guessX][guessY - 2] != 2 || board[guessX + 1][guessY - 2] != 2 ||
			board[guessX + 2][guessY - 2] != 2 || board[guessX + 2][guessY - 1] != 2 ||
			board[guessX + 2][guessY] != 2 || board[guessX + 2][guessY + 1] != 2 ||
			board[guessX + 2][guessY + 2] != 2 || board[guessX + 1][guessY + 2] != 2 ||
			board[guessX][guessY + 2] != 2 || board[guessX - 1][guessY + 2] != 2 ||
			board[guessX - 2][guessY + 2] != 2 || board[guessX - 2][guessY + 1] != 2 ||
			board[guessX - 2][guessY] != 2 || board[guessX - 2][guessY - 1] != 2 ||
			board[guessX - 2][guessY - 2] != 2 || board[guessX - 1][guessY - 2] != 2)
			cout << "Near miss ship 2!" << endl;

		else
			cout << "Near miss ship 3!" << endl;

	}

	return;
}

//function to clear the board when a ship is hit
void changeHitShip(int hitShip, int board[][10])
{
	int i, n;
	for (i = 0; i < 10; i++)
	{
		for (n = 0; n < 10; n++)
		{
			if (board[i][n] == hitShip)
				board[i][n] = 0;
		}
	}
		
	return;
}