#include <iostream>
#include <iomanip>
#include <windows.h>
#include "Blocks.h"
#include "IBlock.h"
#include "TBlock.h"
#include "LBlock.h"
#include "JBlock.h"
#include "ZBlock.h"


using namespace std;

void printBoard(char board[][10]);


int main()
{

	char board[20][10];
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
	startZBlock(boardColors, color, startSpot); //need to start the row as 0
	row = 0;

	printBoard(boardColors);
	cout << endl;

	//move1ZBlock(boardColors, 66, startSpot, 3, row);
	down1ZBlock(boardColors, 66, startSpot, row, doneMoving);

	printBoard(boardColors);
	cout << endl;

	turn1ZBlock(boardColors, 66, startSpot, row);

	printBoard(boardColors);
	cout << endl;

	//move2ZBlock(boardColors, 66, startSpot, 1, row);
	turn2ZBlock(boardColors, 66, startSpot, row);

	printBoard(boardColors);
	cout << endl;


	down1ZBlock(boardColors, 66, startSpot, row, doneMoving);

	


	printBoard(boardColors);


	return 0;
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

