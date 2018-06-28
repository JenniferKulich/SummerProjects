#include <iostream>
#include <time.h>

using namespace std;

void askUser(int &guessX, int &guessY);
bool directHit(int guessX, int guessY, int &numShipsHit, int board[][14]);
bool hitByOne(int guessX, int guessY, int &numShipsHit, int board[][14]);
void missedByTwo(int guessX, int guessY, int board[][14]);
void changeHitShip(int hitShip, int board[][14]);

int main()
{
	int board[14][14] = { 0 };
	int randomXSpot = 0;
	int randomYSpot = 0;
	int guessX = 0;
	int guessY = 0;
	int numShipsHit = 0;

	srand(time(NULL));

	//for loop that will get random spot for all 3 ships
	int i;
	for (i = 1; i < 4; i++)
	{
		//get random spot for ship
		randomXSpot = rand() % 10 + 1;
		randomYSpot = rand() % 10 + 1;

		cout << randomXSpot << endl << randomYSpot << endl;

		//mark random spot of ship
		board[randomXSpot + 1][randomYSpot + 1] = i;
	}
	
	//will loop through for guesses until all 3 ships are taken down
	while (numShipsHit < 3)
	{
		//call function to ask user for guess of spot
		askUser(guessX, guessY);
		
		//change the row and column so compatable with array
		guessX = guessX - 1;
		guessY = guessY - 1;

		bool didHit = true;
		//check if direct hit
		didHit = directHit(guessX, guessY, numShipsHit, board);
		if (didHit == 0)
		{
			// check if ship hit by one space
			didHit = hitByOne(guessX, guessY, numShipsHit, board);
			if (didHit == 0)
			{
				//check if ship was missed by two spaces
				missedByTwo(guessX, guessY, board);
			}
		}		
		
		cout << endl;
	}


	return 0;
}

//function to ask user what their guess is on the ship
void askUser(int &guessX, int &guessY)
{
	//ask user for a spot
	cout << "Enter shot row and column (1-10)" << endl;
	cout << "Row: ";
	cin >> guessX;
	//ask again if guess isn't valid
	while (guessX < 1 || guessX > 10)
	{
		cout << endl << "Row must be between 1 and 10. Please enter another row: ";
		cin >> guessX;
		cout << endl;
	}
	cout << endl << "Column: ";
	cin >> guessY;
	//ask again if guess isn't valid
	while (guessY < 1 || guessY > 10)
	{
		cout << endl << "Column must be between 1 and 10. Please enter another Column: ";
		cin >> guessY;
		cout << endl;
	}
	cout << endl;

	guessX = guessX + 2;
	guessY = guessY + 2;

	return;
}


//function to check if the ship was directly hit
bool directHit(int guessX, int guessY, int &numShipsHit, int board[][14])
{
	//check to see if spot was a hit
	if (board[guessX][guessY] != 0)
	{
		//check if ship one
		if (board[guessX][guessY] == 1)
		{
			cout << "Ship 1 was hit directly!" << endl;
			changeHitShip(1, board);
			numShipsHit = numShipsHit + 1;
			return 1;
		}
		//check if ship two
		else if (board[guessX][guessY] == 2)
		{
			cout << "Ship 2 was hit directly!" << endl;
			changeHitShip(2, board);
			numShipsHit = numShipsHit + 1;
			return 1;
		}
		//if neither ship one or two, it'll be ship three
		else
		{
			cout << "Ship 3 was hit directly!" << endl;
			changeHitShip(3, board);
			numShipsHit = numShipsHit + 1;
			return 1;
		}

	}
	return 0;
}

//function to check if the ship was hit by one spot
bool hitByOne(int guessX, int guessY, int &numShipsHit, int board[][14])
{
	//check if guess is one away from the ship
	if (board[guessX][guessY + 1] != 0 || board[guessX + 1][guessY + 1] != 0 ||
		board[guessX + 1][guessY] != 0 || board[guessX + 1][guessY - 1] != 0 ||
		board[guessX][guessY - 1] != 0 || board[guessX - 1][guessY - 1] != 0 ||
		board[guessX - 1][guessY] != 0 || board[guessX - 1][guessY + 1] != 0)
	{
		//check if ship one
		if (board[guessX][guessY + 1] == 1 || board[guessX + 1][guessY + 1] == 1 ||
			board[guessX + 1][guessY] == 1 || board[guessX + 1][guessY - 1] == 1 ||
			board[guessX][guessY - 1] == 1 || board[guessX - 1][guessY - 1] == 1 ||
			board[guessX - 1][guessY] == 1 || board[guessX - 1][guessY + 1] == 1)
		{
			numShipsHit = numShipsHit + 1;
			cout << "Hit ship 1!" << endl;
			changeHitShip(1, board);
			return 1;
		}

		//check if ship two
		else if (board[guessX][guessY + 1] == 2 || board[guessX + 1][guessY + 1] == 2 ||
			board[guessX + 1][guessY] == 2 || board[guessX + 1][guessY - 1] == 2 ||
			board[guessX][guessY - 1] == 2 || board[guessX - 1][guessY - 1] == 2 ||
			board[guessX - 1][guessY] == 2 || board[guessX - 1][guessY + 1] == 2)
		{
			cout << "Hit ship 2!" << endl;
			changeHitShip(2, board);
			numShipsHit = numShipsHit + 1;
			return 1;
		}

		//if neither ship one or two, it'll be ship three
		else if (board[guessX][guessY + 1] == 3 || board[guessX + 1][guessY + 1] == 3 ||
			board[guessX + 1][guessY] == 3 || board[guessX + 1][guessY - 1] == 3 ||
			board[guessX][guessY - 1] == 3 || board[guessX - 1][guessY - 1] == 3 ||
			board[guessX - 1][guessY] == 3 || board[guessX - 1][guessY + 1] == 3)
		{
			cout << "Hit ship 3!" << endl;
			changeHitShip(3, board);
			numShipsHit = numShipsHit + 1;
			return 1;
		}
	}
	return 0;
}

//function to check if ship was missed by two spots
void missedByTwo(int guessX, int guessY, int board[][14])
{
	//check if within two spots away
	if (board[guessX][guessY - 2] != 0 || board[guessX + 1][guessY - 2] != 0 ||
		board[guessX + 2][guessY - 2] != 0 || board[guessX + 2][guessY - 1] != 0 ||
		board[guessX + 2][guessY] != 0 || board[guessX + 2][guessY + 1] != 0 ||
		board[guessX + 2][guessY + 2] != 0 || board[guessX + 1][guessY + 2] != 0 ||
		board[guessX][guessY + 2] != 0 || board[guessX - 1][guessY + 2] != 0 ||
		board[guessX - 2][guessY + 2] != 0 || board[guessX - 2][guessY + 1] != 0 ||
		board[guessX - 2][guessY] != 0 || board[guessX - 2][guessY - 1] != 0 ||
		board[guessX - 2][guessY - 2] != 0 || board[guessX - 1][guessY - 2] != 0)
	{
		//check if ship one
		if (board[guessX][guessY - 2] == 1 || board[guessX + 1][guessY - 2] == 1 ||
			board[guessX + 2][guessY - 2] == 1 || board[guessX + 2][guessY - 1] == 1 ||
			board[guessX + 2][guessY] == 1 || board[guessX + 2][guessY + 1] != 1 ||
			board[guessX + 2][guessY + 2] == 1 || board[guessX + 1][guessY + 2] == 1 ||
			board[guessX][guessY + 2] == 1 || board[guessX - 1][guessY + 2] == 1 ||
			board[guessX - 2][guessY + 2] == 1 || board[guessX - 2][guessY + 1] == 1 ||
			board[guessX - 2][guessY] == 1 || board[guessX - 2][guessY - 1] == 1 ||
			board[guessX - 2][guessY - 2] == 1 || board[guessX - 1][guessY - 2] == 1)
			cout << "Near miss ship 1!" << endl;

		//check if ship two
		else if (board[guessX][guessY - 2] == 2 || board[guessX + 1][guessY - 2] == 2 ||
			board[guessX + 2][guessY - 2] == 2 || board[guessX + 2][guessY - 1] == 2 ||
			board[guessX + 2][guessY] == 2 || board[guessX + 2][guessY + 1] == 2 ||
			board[guessX + 2][guessY + 2] == 2 || board[guessX + 1][guessY + 2] == 2 ||
			board[guessX][guessY + 2] == 2 || board[guessX - 1][guessY + 2] == 2 ||
			board[guessX - 2][guessY + 2] == 2 || board[guessX - 2][guessY + 1] == 2 ||
			board[guessX - 2][guessY] == 2 || board[guessX - 2][guessY - 1] == 2 ||
			board[guessX - 2][guessY - 2] == 2 || board[guessX - 1][guessY - 2] == 2)
			cout << "Near miss ship 2!" << endl;

		//if neither ship one or two, it'll be ship three
		else if (board[guessX][guessY - 2] == 3 || board[guessX + 1][guessY - 2] == 3 ||
			board[guessX + 2][guessY - 2] == 3 || board[guessX + 2][guessY - 1] == 3 ||
			board[guessX + 2][guessY] == 3 || board[guessX + 2][guessY + 1] == 3 ||
			board[guessX + 2][guessY + 2] == 3 || board[guessX + 1][guessY + 2] == 3 ||
			board[guessX][guessY + 2] == 3 || board[guessX - 1][guessY + 2] == 3 ||
			board[guessX - 2][guessY + 2] == 3 || board[guessX - 2][guessY + 1] == 3 ||
			board[guessX - 2][guessY] == 3 || board[guessX - 2][guessY - 1] == 3 ||
			board[guessX - 2][guessY - 2] == 3 || board[guessX - 1][guessY - 2] == 3)
			cout << "Near miss ship 3!" << endl;

	}

	return;
}

//function to clear the board when a ship is hit
void changeHitShip(int hitShip, int board[][14])
{
	//loop through and change ship number if hit
	int i, n;
	for (i = 0; i < 14; i++)
	{
		for (n = 0; n < 14; n++)
		{
			if (board[i][n] == hitShip)
				board[i][n] = 0;
				
		}
	}
		
	return;
}