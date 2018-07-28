#include <iostream>

using namespace std;

void printBoard(int board[][4]);
bool isBoardFull(int board[][4]);
void moveAllRight(int board[][4]);
void combineRight(int board[][4], bool &isWin);
void moveAllLeft(int board[][4]);
void combineLeft(int board[][4], bool &isWin);
void moveAllUp(int board[][4]);
void combineUp(int board[][4], bool &isWin);
void moveAllDown(int board[][4]);
void combineDown(int board[][4], bool &isWin);



int main()
{
	int board[4][4];
	int i, n;
	int userMove = 0;
	bool isWin = false;
	bool fullBoard;

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
	cout << "Press 'Q' any time to quit the game" << endl;
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

	cin >> userMove;
	while (userMove != 5 && userMove != 2 && userMove != 1 && userMove != 3)
	{
		cout << "Please enter a correct move" << endl;
		cin >> userMove;
	}

	//move everything on the board according to what the user has selected
	

	//check if can move one spot over to combine
	//check if can move two spots over to combine
	//check if can move three spots over to combine

	//test to see if everything is moved
	//add random things to the board
	board[0][0] = 4;
	board[0][2] = 4;
	board[1][3] = 5;
	board[1][2] = 6;
	board[1][0] = 5;
	board[2][2] = 8;
	board[3][0] = 2;
	board[3][1] = 2;
	//board[3][1] = 5;
	printBoard(board);
	moveAllRight(board);
	cout << endl;
	printBoard(board);
	cout << endl;
	combineRight(board, isWin);
	printBoard(board);
	cout << endl;
	moveAllLeft(board);
	printBoard(board);
	cout << endl;
	combineLeft(board, isWin);
	printBoard(board);
	cout << endl;
	moveAllUp(board);
	printBoard(board);
	cout << endl;
	moveAllDown(board);
	printBoard(board);
	cout << endl;

	fullBoard = isBoardFull(board);
	if (fullBoard == true)
	{
		cout << "Sorry! The board is full and a move cannot be made" << endl;
		return 0;
	}


	return 0;
}


//function that will print the board to the screen
void printBoard(int board[][4])
{
	int i, n;

	for (i = 0; i < 4; i++)
	{
		for (n = 0; n < 4; n++)
		{
			cout << board[i][n] << " ";
		}
		
		cout << endl;
	}

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
					numThere = board[3][i];
					board[2][i] = 0;
					board[2][i] = numThere;
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
							numThere = board[3][i];
							board[2][i] = 0;
							board[2][i] = numThere;
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

		//check if row 1 is open
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


		//check if row 2 is open
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
	return;
}