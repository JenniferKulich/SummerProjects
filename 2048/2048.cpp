#include <iostream>

using namespace std;

void printBoard(int board[][4]);
void combineRight(int board[][4], bool &isWin);
void moveAllRight(int board[][4]);

int main()
{
	int board[4][4];
	int i, n;
	int userMove = 0;

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
	board[0][0] = 3;
	board[0][2] = 4;
	board[1][3] = 5;
	board[1][2] = 6;
	board[1][0] = 7;
	board[2][2] = 8;
	board[3][0] = 9;
	//board[3][1] = 5;
	printBoard(board);
	moveAllRight(board);
	cout << endl;
	printBoard(board);




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

//function that will move everything over to the right
void moveAllRight(int board[][4])
{
	int i, n;
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

	//call the function to move everything to the right
	//put things together if can
	//move everything to the right again


	//move everything to the right
	moveAllRight(board);



	////check if one in first spot
	//if (board[0][0] != 0)
	//{
	//	numInSpot = board[0][0];

	//	//check if can combine with second spot
	//	if (board[0][1] == numInSpot)
	//	{
	//		board[0][0] = 0;
	//		board[0][1] = numInSpot * numInSpot;
	//		//check if can move all of the way over
	//		if (board[0][2] == 0)
	//		{
	//			board[0][1] = 0;
	//			board[0][2] == numInSpot * numInSpot;
	//			//move over again if the next spot is zero
	//			if (board[0][3] == 0)
	//			{
	//				board[0][1] = 0;
	//				board[0][3] == numInSpot * numInSpot;
	//			}
	//		}
	//	}

	//	//check if can combine with third spot
	//	if (board[0][2] == numInSpot)
	//	{
	//		board[0][0] = 0;
	//		board[0][2] = numInSpot * numInSpot;
	//		//check if can move all of the way over
	//		if (board[0][3] == 0)
	//		{
	//			board[0][2] = 0;
	//			board[0][3] = numInSpot * numInSpot;
	//		}
	//	}

	//	//check if can combine with fourth spot
	//	if (board[0][3] == numInSpot)
	//	{
	//		board[0][0] = 0;
	//		board[0][3] = numInSpot * numInSpot;
	//	}
	//}

	////check in second spot
	//if (board[0][1] != 0)
	//{
	//	numInSpot = board[0][1];

	//	//check if can combine with third spot
	//	if (board[0][2] == numInSpot)
	//	{
	//		board[0][1] = 0;
	//		board[0][2] = numInSpot * numInSpot;
	//		//check if can move all of the way over
	//		if (board[0][3] == 0)
	//		{
	//			board[0][2] = 0;
	//			board[0][3] = numInSpot * numInSpot;
	//		}
	//	}

	//	//check if can combine with fourth spot
	//	if (board[0][3] == numInSpot)
	//	{
	//		board[0][1] = 0;
	//		board[0][3] = numInSpot * numInSpot;
	//	}

	//}

	////check in third spot
	//if (board[0][2] != 0)
	//{
	//	numInSpot = board[0][2];

	//	//check if can combine with fourth spot
	//	if (board[0][3] == numInSpot)
	//	{
	//		board[0][2] = 0;
	//		board[0][3] = numInSpot * numInSpot;
	//	}

	//}

	//move everything over to the right
	//start backwards



	return;
}