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

//function that will check if a row is completed and then will delete it and move everything down
void checkIfCompleteRow(char boardColors[][10])
{
	int i, n, m, x, z;
	int row = 0;
	bool allFull = true;
	char nameSpot;

	for (i = 19; i > 0; i--)
	{
		for (n = 0; n < 10; n++)
		{
			if (boardColors[i][n] == 00)
				allFull = false;
		}
		//if the entire row is full, record the row
		if (allFull = true)
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
		}
	}


}

//function where everything gets put together
void everythingTogether(char boardColors[][10])
{
	char colorName;
	int userMove;
	int i;

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
	//get user input, 3 for right, 1 for left 2 for down, 6 for turn, 0 for quit

	//make a check to see if can start the block in the right spot, if cannot, move around until can

	//check to see if something in the top line, if there is, then game over

	//check to make sure that a row isn't full
	

	return;
}



//function that will do all of the moves of the O block until none can be made
void allMoveOBlock(char colorName, char boardColors[][10])
{
	int row = 0;
	int startSpot = 0;
	bool doneMoving = false;

	startOBlock(boardColors, colorName, startSpot); //need to start the row as 0

	printBoard(boardColors);
	cout << endl;

	moveOBlock(boardColors, colorName, startSpot, 3, row);

	printBoard(boardColors);
	cout << endl;

	downOBlock(boardColors, colorName, startSpot, row, doneMoving);

	return;
}


//function that will return the character name of what color will be used
char getColorName()
{
	int color;


	//get a random number for the color
	srand(time(NULL));

	//get random number between 1 and 8
	color = rand() % 7 + 1;
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
