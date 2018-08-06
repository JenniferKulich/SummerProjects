#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include "Utilities.h"
#include "Blocks.h"
#include "IBlock.h"
#include "TBlock.h"
#include "LBlock.h"
#include "JBlock.h"
#include "ZBlock.h"
#include "SBlock.h"
#include "OBlock.h"

using namespace std;


//function where everything gets put together
void everythingTogether(char boardColors[][10])
{
	char colorName;
	int userMove;
	int i;
	bool isGameOver;
	int newRandomBlock;
	bool doesQuit;

	//get the random color name for when the block starts
	colorName = getColorName();


	//get random number so a random start block will be picked
	//allMoveOBlock(colorName, boardColors);

	for (i = 0; i < 10; i++)
	{
		boardColors[19][i] = 67;
		boardColors[18][i] = 68;
	}

	printBoard(boardColors);

	checkIfCompleteRow(boardColors);

	printBoard(boardColors);
		
	

	//get a random number between 1 and 7 to determine which block will start first
	//get a random number for the color
	srand(time(NULL));

	//get random number between 1 and 7
	newRandomBlock = rand() % 7 + 1;



	//make a check to see if can start the block in the right spot, if cannot, move around until can

	

	//check to make sure that a row isn't full
	//checkIfCompleteRow(boardColors);

	allMoveJBlock(colorName, boardColors, doesQuit);

	if (doesQuit == true)
		return;
	

	return;
}


//function that will do all of the moves of the I block until none can be made
void allMoveIBlock(char colorName, char boardColors[][10], bool &doesQuit)
{
	int row = 0;
	int startSpot = 0;
	bool doneMoving = false;
	int userInput;
	bool isGameOver;
	bool wasFull = false;
	int typeTurn = 1; //this means it is on the normal, start one

	startIBlock(boardColors, colorName, startSpot); //need to start the row as 0

	printBoard(boardColors);
	cout << endl;

	while (doneMoving != true)
	{
		//get user input, 3 for right, 1 for left 2 for down, 6 for turn, 0 for quit
		cin >> userInput;

		//this will move the block right or left
		if (userInput == 3 || userInput == 1)
		{
			if (typeTurn == 1)
			{
				moveHorizontalIBlock(boardColors, colorName, startSpot, userInput, row);
				downHorizontalIBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else
			{
				moveVerticalIBlock(boardColors, colorName, startSpot, userInput, row);
				downVerticalIBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
		}

		//this will move the block down
		else if (userInput == 2)
		{
			if (typeTurn == 1)
			{
				downHorizontalIBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else
			{
				downVerticalIBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
		}

		//this will turn the block
		else if (userInput == 6)
		{
			//call the function to turn the block and update the turn type
			if (typeTurn == 1)
			{
				turnHorizontalIBlock(boardColors, colorName, startSpot, row);
				printBoard(boardColors);
				cout << endl;
				typeTurn = 2;
			}
			else if (typeTurn == 2)
			{
				turnVerticalIBlock(boardColors, colorName, startSpot, row);
				printBoard(boardColors);
				cout << endl;
				typeTurn = 1;
			}

		}
	
		//this will quit
		else if (userInput == 0)
			doesQuit = true;

		//otherwise, just move the block down
		else
		{
			if (typeTurn == 1)
			{
				downHorizontalIBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else
			{
				downVerticalIBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
		}
		//check to see if done moving is true
		//if it is, break out of the loop to start a new one
		if (doneMoving == true)
		{
			//check to make sure that a row isn't full
			checkIfCompleteRow(boardColors);
			while (wasFull == true)
				checkIfCompleteRow(boardColors);
			//check to see if something in the top line, if there is, then game over
			isGameOver = gameOve(boardColors);
			if (isGameOver == true)
			{
				cout << "Game is over!" << endl;
				doesQuit = true;
				return;
			}
		}
	}

	return;
}



//function that will do all of the moves of the T block until none can be made
void allMoveTBlock(char colorName, char boardColors[][10], bool &doesQuit)
{
	int row = 0;
	int startSpot = 0;
	bool doneMoving = false;
	int userInput;
	bool isGameOver;
	bool wasFull = false;
	int typeTurn = 1; //this means it is on the normal, start one

	startTBlock(boardColors, colorName, startSpot); //need to start the row as 0

	printBoard(boardColors);
	cout << endl;

	while (doneMoving != true)
	{
		//get user input, 3 for right, 1 for left 2 for down, 6 for turn, 0 for quit
		cin >> userInput;

		//this will move the block right or left
		if (userInput == 3 || userInput == 1)
		{
			if (typeTurn == 1)
			{
				move1TBlock(boardColors, colorName, startSpot, userInput, row);
				down1TBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if(typeTurn == 2)
			{
				move2TBlock(boardColors, colorName, startSpot, userInput, row);
				down2TBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 3)
			{
				move3TBlock(boardColors, colorName, startSpot, userInput, row);
				down3TBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else
			{
				move4TBlock(boardColors, colorName, startSpot, userInput, row);
				down4TBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
		}

		//this will move the block down
		else if (userInput == 2)
		{
			if (typeTurn == 1)
			{
				down1TBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 2)
			{
				down2TBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 3)
			{
				down3TBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else
			{
				down4TBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
		}

		//this will turn the block
		else if (userInput == 6)
		{
			//call the function to turn the block and update the turn type
			if (typeTurn == 1)
			{
				turn1TBlock(boardColors, colorName, startSpot, row);
				printBoard(boardColors);
				cout << endl;
				typeTurn = 2;
			}
			else if (typeTurn == 2)
			{
				turn2TBlock(boardColors, colorName, startSpot, row);
				printBoard(boardColors);
				cout << endl;
				typeTurn = 3;
			}
			else if (typeTurn == 3)
			{
				turn3TBlock(boardColors, colorName, startSpot, row);
				printBoard(boardColors);
				cout << endl;
				typeTurn = 4;
			}
			else if (typeTurn == 4)
			{
				turn4TBlock(boardColors, colorName, startSpot, row);
				printBoard(boardColors);
				cout << endl;
				typeTurn = 1;
			}

		}

		//this will quit
		else if (userInput == 0)
			doesQuit = true;

		//otherwise, just move the block down
		else
		{
			if (typeTurn == 1)
			{
				down1TBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 2)
			{
				down2TBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 3)
			{
				down3TBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else
			{
				down4TBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
		}
		//check to see if done moving is true
		//if it is, break out of the loop to start a new one
		if (doneMoving == true)
		{
			//check to make sure that a row isn't full
			checkIfCompleteRow(boardColors);
			while (wasFull == true)
				checkIfCompleteRow(boardColors);
			//check to see if something in the top line, if there is, then game over
			isGameOver = gameOve(boardColors);
			if (isGameOver == true)
			{
				cout << "Game is over!" << endl;
				doesQuit = true;
				return;
			}
		}
	}

	return;
}



//function that will do all of the moves of the L block until none can be made
void allMoveLBlock(char colorName, char boardColors[][10], bool &doesQuit)
{
	int row = 0;
	int startSpot = 0;
	bool doneMoving = false;
	int userInput;
	bool isGameOver;
	bool wasFull = false;
	int typeTurn = 1; //this means it is on the normal, start one

	startLBlock(boardColors, colorName, startSpot); //need to start the row as 2
	row = 2;

	printBoard(boardColors);
	cout << endl;

	while (doneMoving != true)
	{
		//get user input, 3 for right, 1 for left 2 for down, 6 for turn, 0 for quit
		cin >> userInput;

		//this will move the block right or left
		if (userInput == 3 || userInput == 1)
		{
			if (typeTurn == 1)
			{
				move1LBlock(boardColors, colorName, startSpot, userInput, row);
				down1LBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 2)
			{
				move2LBlock(boardColors, colorName, startSpot, userInput, row);
				down2LBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 3)
			{
				move3LBlock(boardColors, colorName, startSpot, userInput, row);
				down3LBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else
			{
				move4LBlock(boardColors, colorName, startSpot, userInput, row);
				down4LBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
		}

		//this will move the block down
		else if (userInput == 2)
		{
			if (typeTurn == 1)
			{
				down1LBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 2)
			{
				down2LBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 3)
			{
				down3LBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else
			{
				down4LBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
		}

		//this will turn the block
		else if (userInput == 6)
		{
			//call the function to turn the block and update the turn type
			if (typeTurn == 1)
			{
				turn1LBlock(boardColors, colorName, startSpot, row);
				printBoard(boardColors);
				cout << endl;
				typeTurn = 2;
			}
			else if (typeTurn == 2)
			{
				turn2LBlock(boardColors, colorName, startSpot, row);
				printBoard(boardColors);
				cout << endl;
				typeTurn = 3;
			}
			else if (typeTurn == 3)
			{
				turn3LBlock(boardColors, colorName, startSpot, row);
				printBoard(boardColors);
				cout << endl;
				typeTurn = 4;
			}
			else if (typeTurn == 4)
			{
				turn4LBlock(boardColors, colorName, startSpot, row);
				printBoard(boardColors);
				cout << endl;
				typeTurn = 1;
			}

		}

		//this will quit
		else if (userInput == 0)
			doesQuit = true;

		//otherwise, just move the block down
		else
		{
			if (typeTurn == 1)
			{
				down1LBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 2)
			{
				down2LBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 3)
			{
				down3LBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else
			{
				down4LBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
		}
		//check to see if done moving is true
		//if it is, break out of the loop to start a new one
		if (doneMoving == true)
		{
			//check to make sure that a row isn't full
			checkIfCompleteRow(boardColors);
			while (wasFull == true)
				checkIfCompleteRow(boardColors);
			//check to see if something in the top line, if there is, then game over
			isGameOver = gameOve(boardColors);
			if (isGameOver == true)
			{
				cout << "Game is over!" << endl;
				doesQuit = true;
				return;
			}
		}
	}

	return;
}



//function that will do all of the moves of the J block until none can be made
void allMoveJBlock(char colorName, char boardColors[][10], bool &doesQuit)
{
	int row = 0;
	int startSpot = 0;
	bool doneMoving = false;
	int userInput;
	bool isGameOver;
	bool wasFull = false;
	int typeTurn = 1; //this means it is on the normal, start one

	startJBlock(boardColors, colorName, startSpot); //need to start the row as 1
	row = 1;

	printBoard(boardColors);
	cout << endl;

	while (doneMoving != true)
	{
		//get user input, 3 for right, 1 for left 2 for down, 6 for turn, 0 for quit
		cin >> userInput;

		//this will move the block right or left
		if (userInput == 3 || userInput == 1)
		{
			if (typeTurn == 1)
			{
				move1JBlock(boardColors, colorName, startSpot, userInput, row);
				down1JBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 2)
			{
				move2JBlock(boardColors, colorName, startSpot, userInput, row);
				down2JBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 3)
			{
				move3JBlock(boardColors, colorName, startSpot, userInput, row);
				down3JBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else
			{
				move4JBlock(boardColors, colorName, startSpot, userInput, row);
				down4JBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
		}

		//this will move the block down
		else if (userInput == 2)
		{
			if (typeTurn == 1)
			{
				down1JBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 2)
			{
				down2JBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 3)
			{
				down3JBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else
			{
				down4JBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
		}

		//this will turn the block
		else if (userInput == 6)
		{
			//call the function to turn the block and update the turn type
			if (typeTurn == 1)
			{
				turn1JBlock(boardColors, colorName, startSpot, row);
				printBoard(boardColors);
				cout << endl;
				typeTurn = 2;
			}
			else if (typeTurn == 2)
			{
				turn2JBlock(boardColors, colorName, startSpot, row);
				printBoard(boardColors);
				cout << endl;
				typeTurn = 3;
			}
			else if (typeTurn == 3)
			{
				turn3JBlock(boardColors, colorName, startSpot, row);
				printBoard(boardColors);
				cout << endl;
				typeTurn = 4;
			}
			else if (typeTurn == 4)
			{
				turn4JBlock(boardColors, colorName, startSpot, row);
				printBoard(boardColors);
				cout << endl;
				typeTurn = 1;
			}

		}

		//this will quit
		else if (userInput == 0)
			doesQuit = true;

		//otherwise, just move the block down
		else
		{
			if (typeTurn == 1)
			{
				down1JBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 2)
			{
				down2JBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else if (typeTurn == 3)
			{
				down3JBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
			else
			{
				down4JBlock(boardColors, colorName, startSpot, row, doneMoving);
				printBoard(boardColors);
				cout << endl;
			}
		}
		//check to see if done moving is true
		//if it is, break out of the loop to start a new one
		if (doneMoving == true)
		{
			//check to make sure that a row isn't full
			checkIfCompleteRow(boardColors);
			while (wasFull == true)
				checkIfCompleteRow(boardColors);
			//check to see if something in the top line, if there is, then game over
			isGameOver = gameOve(boardColors);
			if (isGameOver == true)
			{
				cout << "Game is over!" << endl;
				doesQuit = true;
				return;
			}
		}
	}

	return;
}



//function that will do all of the moves of the Z block until none can be made
void allMoveZBlock(char colorName, char boardColors[][10], bool &doesQuit)
{


	return;
}



//function that will do all of the moves of the S block until none can be made
void allMoveSBlock(char colorName, char boardColors[][10], bool &doesQuit)
{


	return;
}

//function that will do all of the moves of the O block until none can be made
void allMoveOBlock(char colorName, char boardColors[][10], bool &doesQuit)
{
	int row = 0;
	int startSpot = 0;
	bool doneMoving = false;
	int userInput;
	bool isGameOver;
	bool wasFull = false;

	startOBlock(boardColors, colorName, startSpot); //need to start the row as 0

	printBoard(boardColors);
	cout << endl;
	
	while (doneMoving != true)
	{
		//get user input, 3 for right, 1 for left 2 for down, 6 for turn, 0 for quit
		cin >> userInput;

		if (userInput == 3 || userInput == 1)
		{
			moveOBlock(boardColors, colorName, startSpot, userInput, row);
			printBoard(boardColors);
			cout << endl;
			downOBlock(boardColors, colorName, startSpot, row, doneMoving);
			printBoard(boardColors);
			cout << endl;
		}
		else if (userInput == 2)
		{
			downOBlock(boardColors, colorName, startSpot, row, doneMoving);
			printBoard(boardColors);
			cout << endl;
		}
		else if (userInput == 0)
			doesQuit = true;
		else
		{
			downOBlock(boardColors, colorName, startSpot, row, doneMoving);
			printBoard(boardColors);
			cout << endl;
		}
		//check to see if done moving is true
		//if it is, break out of the loop to start a new one
		if (doneMoving == true)
		{
			//check to make sure that a row isn't full
			checkIfCompleteRow(boardColors);
			while(wasFull == true)
				checkIfCompleteRow(boardColors);
			//check to see if something in the top line, if there is, then game over
			isGameOver = gameOve(boardColors);
			if (isGameOver == true)
			{
				cout << "Game is over!" << endl;
				doesQuit = true;
				return;
			}
		}
	}
	

	return;
}


//function that will check if a row is completed and then will delete it and move everything down
void checkIfCompleteRow(char boardColors[][10])
{
	int i, n, m, x, z;
	int row = 0;
	bool allFull = true;
	char nameSpot;
	

	for (i = 19; i > 0; --i)
	{
		for (n = 0; n < 10; n++)
		{
			if (boardColors[i][n] == 00)
				allFull = false;
		}
		//if the entire row is full, record the row
		if (allFull == true)
		{
			row = i;
			//eliminate the whole row 
			for (m = 0; m < 10; m++)
				boardColors[row][m] = 00;
			//move everything down
			for (x = row - 1; x > 0; x--)
			{
				for (z = 0; z < 10; z++)
				{
					nameSpot = boardColors[x][z];
					boardColors[x][z] = 00;
					boardColors[x + 1][z] = nameSpot;
				}
			}
			i++;
		}
	}
		

	return;
}

//function that will check if there is something in the top row. If there is, the game is over
bool gameOve(char boardColors[][10])
{
	int i;

	//loop through to check the whole first row
	for (i = 0; i < 10; i++)
	{
		if (boardColors[0][i] != 00)
			return true;
	}

	return false;
}

//function that will return the character name of what color will be used
char getColorName()
{
	int color;


	//get a random number for the color
	srand(time(NULL));

	//get random number between 1 and 8
	color = rand() % 8 + 1;
	/*
	The different color codes are

	0   BLACK
	1   BLUE      "B" char 66 - 2
	2   GREEN     "G" char 71 - 5
	3   CYAN
	4   RED        "R"  char 82 - 7
	5   MAGENTA    "M" char 77 - 2
	6   BROWN      "W"  char - 87
	7   LIGHTGRAY
	8   DARKGRAY
	9   LIGHTBLUE   "L" char 76 - 1
	10  LIGHTGREEN
	11  LIGHTCYAN
	12  LIGHTRED
	13  LIGHTMAGENTA
	14  YELLOW        "Y" char 89 - 4
	15  WHITE
	*/

	//light blue
	if (color == 1)
		return 76; //"L"
				   //blue
	else if (color == 2)
		return 66; //"B"
				   //magenta
	else if (color == 3)
		return 77; //"M"
				   //yellow
	else if (color == 4)
		return 89; //"Y"
				   //green
	else if (color == 5)
		return 71; //"G"
				   //brown
	else if (color == 6)
		return 87; //"W"
	else    //red----- color == 7
		return 82; //"R"

}


//function that will print the board to the screen
void printBoard(char board[][10])
{
	int i, n;
	char vl = (char)186; //vertical double line
	char hl = (char)205; //horizontal double line
	char ulc = (char)201; //upper left corner
	char urc = (char)187; //upper right corner
	char llc = (char)200; //lower left corner
	char lrc = (char)188; //lower right corner

						  //set the border and everything inside to white- everything inside should not be white though
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	//top line
	cout << ulc << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl <<
		hl << hl << hl << hl << hl << hl << hl << hl << hl << urc << endl;

	//loop through and print the board
	for (i = 0; i < 20; i++)
	{
		cout << vl;
		for (n = 0; n < 10; n++)
		{
			if (n == 9)
				cout << board[i][n];
			else
				cout << board[i][n] << " ";
		}

		cout << vl << endl;
	}

	//bottom row
	cout << llc << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl <<
		hl << hl << hl << hl << hl << hl << hl << hl << hl << lrc << endl;

	return;
}
