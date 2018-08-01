#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void printBoard(int board[][4]);
bool isBoardFull(int board[][4]);
void getOrigionalBoard(int board[][4], int origionalBoard[][4]);
bool checkIfOrigionalBoard(int board[][4], int origionalBoard[][4]);
void placeNewRandom(int board[][4]);
void moveAllRight(int board[][4]);
void combineRight(int board[][4], bool &isWin);
void moveAllLeft(int board[][4]);
void combineLeft(int board[][4], bool &isWin);
void moveAllUp(int board[][4]);
void combineUp(int board[][4], bool &isWin);
void moveAllDown(int board[][4]);
void combineDown(int board[][4], bool &isWin);

/*
if everything already moved over as far as possible and combination
cannot be made, then nothing will be done and user must input a new direction
No new number will be added.

do an origional board check. if they're the same, then if they're the same,
don't place a new random number.

*/


int main()
{
	int board[4][4];
	int origionalBoard[4][4];
	int i, n;
	int userMove = 0;
	bool isWin = false;
	bool fullBoard;
	bool isOrigional;

	//set the whole board to zero
	for (i = 0; i < 4; i++)
	{
		for (n = 0; n < 4; n++)
			board[i][n] = 0;
	}

	//initialize the board

	board[3][3] = 2;
	board[3][2] = 2;

	//print out the game begin
	cout << "Game has begun" << endl;
	cout << "Press 0 any time to QUIT the game" << endl;
	cout << "Press 5 for UP" << endl;
	cout << "Press 2 for DOWN" << endl;
	cout << "Press 1 for LEFT" << endl;
	cout << "Press 3 for RIGHT" << endl;


	//print the board
	printBoard(board);

	//get user which way they would like to move the player
	//5 is UP
	//2 is DOWN
	//1 is LEFT
	//3 is RIGHT


	//move everything on the board according to what the user has selected
	
	//loop through until the puzzle is won
	do {

		//ask the user what move they would like to make
		cin >> userMove;
		while (userMove != 5 && userMove != 2 && userMove != 1 && userMove != 3
			&& userMove != 0)
		{
			cout << "Please enter a correct move" << endl;
			cin >> userMove;
		}


		//if user selected 0, quit the game
		if (userMove == 0)
			return 0;

		//if the user selected 5, do the up move
		if (userMove == 5)
		{
			getOrigionalBoard(board, origionalBoard);
			moveAllUp(board);
			combineUp(board, isWin);
		}

		//if the user selected 2, do the down move
		else if (userMove == 2)
		{
			getOrigionalBoard(board, origionalBoard);
			moveAllDown(board);
			combineDown(board, isWin);
		}

		//if the user selected 1, do the left move
		else if (userMove == 1)
		{
			getOrigionalBoard(board, origionalBoard);
			moveAllLeft(board);
			combineLeft(board, isWin);
		}

		//if the user selected 3, do the right move
		else if (userMove == 3)
		{
			getOrigionalBoard(board, origionalBoard);
			moveAllRight(board);
			combineRight(board, isWin);
		}

		//check if the board is full
		fullBoard = isBoardFull(board);
		if (fullBoard == true)
		{
			cout << "Sorry! The board is full and a move can't be made" << endl;
			return 0;
		}

		//check if the board is the same as the origional board
		//if the board is not full, and is not origional board, add a new number
		isOrigional = checkIfOrigionalBoard(board, origionalBoard);
		if (isOrigional == false)
		{
			placeNewRandom(board);
			system("CLS");
			printBoard(board);
		}
		else
			printBoard(board);

		
		
		
	} while (isWin == false);
	
	
	
	return 0;
}


//function that will print the board to the screen
void printBoard(int board[][4])
{
	int i, n;
	char ulc = (char)218;
	char hl = (char)196;
	char urc = (char)191;
	char vl = (char)179;
	char blc = (char)192;
	char brc = (char)217;

	cout << endl;
	//top row
	cout << ulc  << hl << hl << hl << hl << hl << hl << hl << hl
		<< hl << hl << hl << hl << hl << hl << hl << hl << hl << hl
		<< hl << hl << hl << hl << hl << hl << hl << urc << endl;

	for (i = 0; i < 4; i++)
	{
		cout << vl << "    ";
		for (n = 0; n < 4; n++)
		{
			
			if (board[i][n] < 10)
				cout << board[i][n] << "    ";
			if (board[i][n] < 100 && board[i][n] > 10)
				cout << board[i][n] << "   ";
			if (board[i][n] > 100 && board[i][n] < 1000)
				cout << board[i][n] << "  ";
			if (board[i][n] > 1000)
				cout << board[i][n] << " ";
		}
		
		cout << " " << vl << endl;
	}
	//bottom row
	cout << blc << hl << hl << hl << hl << hl << hl << hl << hl
		<< hl << hl << hl << hl << hl << hl << hl << hl << hl << hl
		<< hl << hl << hl << hl << hl << hl << hl << brc << endl;


	return;
}


//function that will check if the entire board is full and no moves can be made
bool isBoardFull(int board[][4])
{
	int i, n;

	//loop through and look for a 0
	//if there is a zero, the board is not full
	for (i = 0; i < 4; i++)
	{
		for (n = 0; n < 4; n++)
		{
			if (board[i][n] == 0)
				return false;
		}
	}

	return true;
}


//function that will copy the board into a new board which will be done
//before anything will be done to the board
//used as an origional board check
void getOrigionalBoard(int board[][4], int origionalBoard[][4])
{
	int i, n;

	//copy the board to the origional board
	for (i = 0; i < 4; i++)
	{
		for (n = 0; n < 4; n++)
		{
			origionalBoard[i][n] = board[i][n];
		}
	}
	return;
}


//function that will compare the origional board to the actual board
bool checkIfOrigionalBoard(int board[][4], int origionalBoard[][4])
{
	int i, n;
	bool isSame = true; 
	int boardNumber, origionalBoardNumber;

	//loop through and compare the board numbers
	for (i = 0; i < 4; i++)
	{
		for (n = 0; n < 4; n++)
		{
			boardNumber = board[i][n];
			origionalBoardNumber = origionalBoard[i][n];
			if (boardNumber != origionalBoardNumber)
				isSame = false;
		}
	}
	
	if (isSame == false)
		return false;
	else
		return true;
}


//function that will place a new number on the board on a random location
void placeNewRandom(int board[][4])
{
	int newNum;
	int randomRow;
	int randomColumn;

	srand(time(NULL));

	//get random number either 2 or 4
	newNum = 2 * (rand() % 2 + 1);

	//get random number for row and column to place number
	randomRow = rand() % 3;
	randomColumn = rand() % 3;

	//if cannot place number on board, get new place to put number
	while (board[randomRow][randomColumn] != 0)
	{
		randomRow = rand() % 3;
		randomColumn = rand() % 3;
	}
	
	//set the board to the new random number
	board[randomRow][randomColumn] = newNum;
	

	return;
}


//function that will move everything over to the right
void moveAllRight(int board[][4])
{
	int i;
	int numThere = 0;

	for (i = 0; i < 4; i++)
	{
		//check if the end is open
		if (board[i][3] == 0)
		{
			if (board[i][2] != 0)
			{
				numThere = board[i][2];
				board[i][2] = 0;
				board[i][3] = numThere;
			}
			else if (board[i][2] == 0)
			{
				if (board[i][1] != 0)
				{
					numThere = board[i][1];
					board[i][1] = 0;
					board[i][2] = numThere;
					if (board[i][3] == 0)
					{
						numThere = board[i][2];
						board[i][2] = 0;
						board[i][3] = numThere;
					}
				}
				else if (board[i][1] == 0)
				{
					if (board[i][0] != 0)
					{
						numThere = board[i][0];
						board[i][0] = 0;
						board[i][1] = numThere;
						if (board[i][2] == 0)
						{
							numThere = board[i][1];
							board[i][1] = 0;
							board[i][2] = numThere;
							if (board[i][3] == 0)
							{
								numThere = board[i][2];
								board[i][2] = 0;
								board[i][3] = numThere;
							}
						}
					}
				}
			}
		}

		//check if spot 3 is open
		if (board[i][2] == 0)
		{
			if (board[i][1] != 0)
			{
				numThere = board[i][1];
				board[i][1] = 0;
				board[i][2] = numThere;
				if (board[i][3] == 0)
				{
					numThere = board[i][2];
					board[i][2] = 0;
					board[i][3] = numThere;
				}
			}
			else if (board[i][1] == 0)
			{
				if (board[i][0] != 0)
				{
					numThere = board[i][0];
					board[i][0] = 0;
					board[i][1] = numThere;
					if (board[i][2] == 0)
					{
						numThere = board[i][1];
						board[i][1] = 0;
						board[i][2] = numThere;
						if (board[i][3] == 0)
						{
							numThere = board[i][2];
							board[i][2] = 0;
							board[i][3] = numThere;
						}
					}
				}
			}
		}

		//check if spot 2 is open
		if (board[i][1] == 0)
		{
			if (board[i][0] != 0)
			{
				numThere = board[i][0];
				board[i][0] = 0;
				board[i][1] = numThere;
				if (board[i][2] == 0)
				{
					numThere = board[i][1];
					board[i][1] = 0;
					board[i][2] = numThere;
					if (board[i][3] == 0)
					{
						numThere = board[i][2];
						board[i][2] = 0;
						board[i][3] = numThere;
					}
				}
			}
		}
	}
	

	return;
}


//function that will handle the movement right
void combineRight(int board[][4], bool &isWin)
{
	int numInSpot = 0;
	int i;
	
	//move everything to the right
	moveAllRight(board);

	//put things together
	//start on the left side and work over
	//will only do anything if the right most and second right most column has number
	for (i = 0; i < 4; i++)
	{
		if (board[i][3] != 0 && board[i][2] != 0)
		{
			numInSpot = board[i][3];
			//if the next one is combineable, combine them and move everything over
			if (board[i][2] == numInSpot)
			{
				board[i][2] = 0;
				board[i][3] = numInSpot * 2;
				moveAllRight(board);
				if (numInSpot * 2 == 2048)
				{
					isWin = true;
					return;
				}
			}

			//check if there's a number in third right most spot
			//if there is a number, see if can combine
			if (board[i][1] != 0)
			{
				numInSpot = board[i][1];
				if (board[i][2] == numInSpot)
				{
					board[i][1] = 0;
					board[i][2] = numInSpot * 2;
					moveAllRight(board);
					if (numInSpot * 2 == 2048)
					{
						isWin = true;
						return;
					}
				}

				//check if there's anumber in the fourth right most spot
				//if there is a number, see if can combine
				if (board[i][0] != 0)
				{
					numInSpot = board[i][0];
					if (board[i][1] == numInSpot)
					{
						board[i][0] = 0;
						board[i][1] = numInSpot * 2;
						moveAllRight(board);
						if (numInSpot * 2 == 2048)
						{
							isWin = true;
							return;
						}
					}
				}

			}
		}
	}
	
	return;
}


//function that will move everything over to the left
void moveAllLeft(int board[][4])
{
	int i;
	int numThere = 0;


	for (i = 0; i < 4; i++)
	{
		//check if front is open
		if (board[i][0] == 0)
		{
			if (board[i][1] != 0)
			{
				numThere = board[i][1];
				board[i][1] = 0;
				board[i][0] = numThere;
			}
			else if (board[i][1] == 0)
			{
				if (board[i][2] != 0)
				{
					numThere = board[i][2];
					board[i][2] = 0;
					board[i][1] = numThere;
					if (board[i][0] == 0)
					{
						numThere = board[i][1];
						board[i][1] = 0;
						board[i][0] = numThere;
					}
				}
				else if (board[i][2] == 0)
				{
					if (board[i][3] != 0)
					{
						numThere = board[i][3];
						board[i][3] = 0;
						board[i][2] = numThere;
						if (board[i][1] == 0)
						{
							numThere = board[i][2];
							board[i][2] = 0;
							board[i][1] = numThere;
							if (board[i][0] == 0)
							{
								numThere = board[i][1];
								board[i][1] = 0;
								board[i][0] = numThere;
							}
						}
					}
				}
			}
		}
		
		//check if spot 2 is open
		if (board[i][1] == 0)
		{
			if (board[i][2] != 0)
			{
				numThere = board[i][2];
				board[i][2] = 0;
				board[i][1] = numThere;
				if (board[i][0] == 0)
				{
					numThere = board[i][1];
					board[i][1] = 0;
					board[i][0] = numThere;
				}
			}
			else if (board[i][2] == 0)
			{
				if (board[i][3] != 0)
				{
					numThere = board[i][3];
					board[i][3] = 0;
					board[i][2] = numThere;
					if (board[i][1] == 0)
					{
						numThere = board[i][2];
						board[i][2] = 0;
						board[i][1] = numThere;
						if (board[i][0] == 0)
						{
							numThere = board[i][1];
							board[i][1] = 0;
							board[i][0] = numThere;
						}
					}
				}
			}
		}
		

		//check if spot 3 is open
		if (board[i][2] == 0)
		{
			if (board[i][3] != 0)
			{
				numThere = board[i][3];
				board[i][3] = 0;
				board[i][2] = numThere;
				if (board[i][1] == 0)
				{
					numThere = board[i][2];
					board[i][2] = 0;
					board[i][1] = numThere;
					if (board[i][0] == 0)
					{
						numThere = board[i][1];
						board[i][1] = 0;
						board[i][0] = numThere;
					}
				}
			}
		}
		
	}

	return;
}


//function that will handle the movement left
void combineLeft(int board[][4], bool &isWin)
{
	int numInSpot = 0;
	int i;

	//move everything to the right
	moveAllLeft(board);

	//put things together
	//start on the right side and work over
	//will only do anything if the left most and second left most column has number
	for (i = 0; i < 4; i++)
	{
		if (board[i][0] != 0 && board[i][1] != 0)
		{
			numInSpot = board[i][0];
			//if the next one is combineable, combine them and move everything over
			if (board[i][1] == numInSpot)
			{
				board[i][1] = 0;
				board[i][0] = numInSpot * 2;
				moveAllLeft(board);
				if (numInSpot * 2 == 2048)
				{
					isWin = true;
					return;
				}
			}

			//check if there's a number in third left most spot
			//if there is a number, see if can combine
			if (board[i][2] != 0)
			{
				numInSpot = board[i][2];
				if (board[i][1] == numInSpot)
				{
					board[i][2] = 0;
					board[i][1] = numInSpot * 2;
					moveAllLeft(board);
					if (numInSpot * 2 == 2048)
					{
						isWin = true;
						return;
					}
				}

				//check if there's anumber in the fourth left most spot
				//if there is a number, see if can combine
				if (board[i][3] != 0)
				{
					numInSpot = board[i][3];
					if (board[i][2] == numInSpot)
					{
						board[i][3] = 0;
						board[i][2] = numInSpot * 2;
						moveAllLeft(board);
						if (numInSpot * 2 == 2048)
						{
							isWin = true;
							return;
						}
					}
				}

			}
		}
	}


	return;
}


//function that will move everything up
void moveAllUp(int board[][4])
{
	int i;
	int numThere = 0;

	//check if the top row is open
	for (i = 0; i < 4; i++)
	{
		//check if front is open
		if (board[0][i] == 0)
		{
			if (board[1][i] != 0)
			{
				numThere = board[1][i];
				board[1][i] = 0;
				board[0][i] = numThere;
			}
			else if (board[1][i] == 0)
			{
				if (board[2][i] != 0)
				{
					numThere = board[2][i];
					board[2][i] = 0;
					board[1][i] = numThere;
					if (board[0][i] == 0)
					{
						numThere = board[1][i];
						board[1][i] = 0;
						board[0][i] = numThere;
					}
				}
				else if (board[2][i] == 0)
				{
					if (board[3][i] != 0)
					{
						numThere = board[3][i];
						board[3][i] = 0;
						board[2][i] = numThere;
						if (board[1][i] == 0)
						{
							numThere = board[2][i];
							board[2][i] = 0;
							board[1][i] = numThere;
							if (board[0][i] == 0)
							{
								numThere = board[1][i];
								board[1][i] = 0;
								board[0][i] = numThere;
							}
						}
					}
				}
			}
		}

		//check if spot 2 is open
		if (board[1][i] == 0)
		{
			if (board[2][i] != 0)
			{
				numThere = board[2][i];
				board[2][i] = 0;
				board[1][i] = numThere;
				if (board[0][i] == 0)
				{
					numThere = board[1][i];
					board[1][i] = 0;
					board[0][i] = numThere;
				}
			}
			else if (board[2][i] == 0)
			{
				if (board[3][i] != 0)
				{
					numThere = board[3][i];
					board[3][i] = 0;
					board[2][i] = numThere;
					if (board[1][i] == 0)
					{
						numThere = board[2][i];
						board[2][i] = 0;
						board[1][i] = numThere;
						if (board[0][i] == 0)
						{
							numThere = board[1][i];
							board[1][i] = 0;
							board[0][i] = numThere;
						}
					}
				}
			}
		}


		//check if spot 3 is open
		if (board[2][i] == 0)
		{
			if (board[3][i] != 0)
			{
				numThere = board[3][i];
				board[3][i] = 0;
				board[2][i] = numThere;
				if (board[1][i] == 0)
				{
					numThere = board[2][i];
					board[2][i] = 0;
					board[1][i] = numThere;
					if (board[0][i] == 0)
					{
						numThere = board[1][i];
						board[1][i] = 0;
						board[0][i] = numThere;
					}
				}
			}
		}

	}
	

	return;
}


//function that will handle the movement up
void combineUp(int board[][4], bool &isWin)
{
	int numInSpot = 0;
	int i;

	//move everything to the right
	moveAllUp(board);

	//put things together
	//start on the top side and work up
	//will only do anything if the up most and second up most column has number
	for (i = 0; i < 4; i++)
	{
		if (board[0][i] != 0 && board[1][i] != 0)
		{
			numInSpot = board[0][i];
			//if the next one is combineable, combine them and move everything over
			if (board[1][i] == numInSpot)
			{
				board[1][i] = 0;
				board[0][i] = numInSpot * 2;
				moveAllUp(board);
				if (numInSpot * 2 == 2048)
				{
					isWin = true;
					return;
				}
			}

			//check if there's a number in third up most spot
			//if there is a number, see if can combine
			if (board[2][i] != 0)
			{
				numInSpot = board[2][i];
				if (board[1][i] == numInSpot)
				{
					board[2][i] = 0;
					board[1][i] = numInSpot * 2;
					moveAllUp(board);
					if (numInSpot * 2 == 2048)
					{
						isWin = true;
						return;
					}
				}

				//check if there's anumber in the fourth up most spot
				//if there is a number, see if can combine
				if (board[3][i] != 0)
				{
					numInSpot = board[3][i];
					if (board[2][i] == numInSpot)
					{
						board[3][i] = 0;
						board[2][i] = numInSpot * 2;
						moveAllUp(board);
						if (numInSpot * 2 == 2048)
						{
							isWin = true;
							return;
						}
					}
				}

			}
		}
	}
	return;
}


//function that will move everything down
void moveAllDown(int board[][4])
{
	int i;
	int numThere = 0;

	for (i = 0; i < 4; i++)
	{
		//check if the bottom row is open
		if (board[3][i] == 0)
		{
			if (board[2][i] != 0)
			{
				numThere = board[2][i];
				board[2][i] = 0;
				board[3][i] = numThere;
			}
			else if (board[2][i] == 0)
			{
				if (board[1][i] != 0)
				{
					numThere = board[1][i];
					board[1][i] = 0;
					board[2][i] = numThere;
					if (board[3][i] == 0)
					{
						numThere = board[2][i];
						board[2][i] = 0;
						board[3][i] = numThere;
					}
				}
				else if (board[1][i] == 0)
				{
					if (board[0][i] != 0)
					{
						numThere = board[0][i];
						board[0][i] = 0;
						board[1][i] = numThere;
						if (board[2][i] == 0)
						{
							numThere = board[1][i];
							board[1][i] = 0;
							board[2][i] = numThere;
							if (board[3][i] == 0)
							{
								numThere = board[2][i];
								board[2][i] = 0;
								board[3][i] = numThere;
							}
						}
					}
				}
			}
		}

		//check if row 2 is open
		if (board[2][i] == 0)
		{
			if (board[1][i] != 0)
			{
				numThere = board[1][i];
				board[1][i] = 0;
				board[2][i] = numThere;
				if (board[3][i] == 0)
				{
					numThere = board[2][i];
					board[2][i] = 0;
					board[3][i] = numThere;
				}
			}
			else if (board[1][i] == 0)
			{
				if (board[0][i] != 0)
				{
					numThere = board[0][i];
					board[0][i] = 0;
					board[1][i] = numThere;
					if (board[2][i] == 0)
					{
						numThere = board[1][i];
						board[1][i] = 0;
						board[2][i] = numThere;
						if (board[3][i] == 0)
						{
							numThere = board[2][i];
							board[2][i] = 0;
							board[3][i] = numThere;
						}
					}
				}
			}
		}

		//check if row 1 is open
		if (board[1][i] == 0)
		{
			if (board[0][i] != 0)
			{
				numThere = board[0][i];
				board[0][i] = 0;
				board[1][i] = numThere;
				if (board[2][i] == 0)
				{
					numThere = board[1][i];
					board[1][i] = 0;
					board[2][i] = numThere;
					if (board[3][i] == 0)
					{
						numThere = board[2][i];
						board[2][i] = 0;
						board[3][i] = numThere;
					}
				}
			}
		}
	}

	return;
}


//function that will handle the movement down
void combineDown(int board[][4], bool &isWin)
{
	int numInSpot = 0;
	int i;

	//move everything to the right
	moveAllDown(board);

	//put things together
	//start on the bottom side and work over
	//will only do anything if the bottom most and second bottom most column has number
	for (i = 0; i < 4; i++)
	{
		if (board[3][i] != 0 && board[2][i] != 0)
		{
			numInSpot = board[3][i];
			//if the next one is combineable, combine them and move everything over
			if (board[2][i] == numInSpot)
			{
				board[2][i] = 0;
				board[3][i] = numInSpot * 2;
				moveAllDown(board);
				if (numInSpot * 2 == 2048)
				{
					isWin = true;
					return;
				}
			}

			//check if there's a number in third bottom most spot
			//if there is a number, see if can combine
			if (board[1][i] != 0)
			{
				numInSpot = board[1][i];
				if (board[2][i] == numInSpot)
				{
					board[1][i] = 0;
					board[2][i] = numInSpot * 2;
					moveAllDown(board);
					if (numInSpot * 2 == 2048)
					{
						isWin = true;
						return;
					}
				}

				//check if there's anumber in the fourth bottom most spot
				//if there is a number, see if can combine
				if (board[0][i] != 0)
				{
					numInSpot = board[0][i];
					if (board[1][i] == numInSpot)
					{
						board[0][i] = 0;
						board[1][i] = numInSpot * 2;
						moveAllDown(board);
						if (numInSpot * 2 == 2048)
						{
							isWin = true;
							return;
						}
					}
				}

			}
		}
	}

	return;
}