#include <iostream>
#include <iomanip>
#include <windows.h>
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



int main()
{

	char boardColors[20][10];
	int i, n;
	int startSpot = 0;
	bool doneMoving;
	int row = 0;

	//initialize the board colors to blank- no colors in there
	for (i = 0; i < 20; i++)
	{
		for (n = 0; n < 10; n++)
			boardColors[i][n] = 00; //nothing in the spot based on colors
	}

	/*int i, n;

	for (i = 0; i < 20; i++)
	{
		for (n = 0; n < 10 ; n++)
		{
			board[i][n] = 66;
		}
	}*/
	/*
	The different color codes are

	0   BLACK
	1   BLUE
	2   GREEN
	3   CYAN
	4   RED
	5   MAGENTA
	6   BROWN
	7   LIGHTGRAY
	8   DARKGRAY
	9   LIGHTBLUE
	10  LIGHTGREEN
	11  LIGHTCYAN
	12  LIGHTRED
	13  LIGHTMAGENTA
	14  YELLOW
	15  WHITE
	*/

	//what is needed to change colors or text
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "HELLO!\n\n";
	int color = 1;

	//startIBlock(boardColors, color, startSpot); //need to start the row as 0
	//startTBlock(boardColors, color, startSpot); //need to start the row as 0
	//startLBlock(boardColors, color, startSpot); //need to start the row as 2
	//row = 2;
	//startJBlock(boardColors, color, startSpot); //need to start the row as 1
	//row = 1;
	//startZBlock(boardColors, color, startSpot); //need to start the row as 0
	//row = 0;
	//startSBlock(boardColors, color, startSpot); //need to start the row as 0
	//row = 0;
	//startOBlock(boardColors, color, startSpot); //need to start the row as 0

	//printBoard(boardColors);
	//cout << endl;

	//moveOBlock(boardColors, 66, startSpot, 3, row);

	//printBoard(boardColors);
	//cout << endl;

	//downOBlock(boardColors, 66, startSpot, row, doneMoving);

	//printBoard(boardColors);


	everythingTogether(boardColors);


	return 0;
}








