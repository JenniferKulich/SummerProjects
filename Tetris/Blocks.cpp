#include "Blocks.h"

//where the functions are written


//function that will start the I block when it appears
void startIBlock(char boardColors[][10], int color, int &startSpot)
{
	char colorName;
	int i;

	//get a random number where the left end should start
	//make sure it is a number less than 6
	srand(time(NULL));

	//get random number between 0 and 6
	startSpot = rand() % 6;

	//call the color name function to get the name to put into the board
	colorName = getColorName(color);

	
	//loop through to put the color name on to the board
	for (i = startSpot; i < startSpot + 4; i++)
		boardColors[0][i] = colorName;


	return;
}


//function that will start the J block when it appears 
void startJBlock(char boardColors[][10], int color, int &startSpot)
{
	char colorName;
	int i;

	//get a random number where the left end should start
	//make sure it is a number less than 8
	srand(time(NULL));

	//get random number between 1 and 8
	startSpot = rand() % 8 + 1;

	//call the color name function to get the name to put into the board
	colorName = getColorName(color);


	//go through and put the color name on the board
	for (i = 0; i < 3; i++ )
		boardColors[i][startSpot] = colorName;
	boardColors[2][startSpot - 1] = colorName;


	return;
}


//function that will start the L block when it appears
void startLBlock(char boardColors[][10], int color, int &startSpot)
{
	char colorName;
	int i;

	//get a random number where the left end should start
	//make sure it is a number less than 7
	srand(time(NULL));

	//get random number between 0 and 7
	startSpot = rand() % 7;

	//call the color name function to get the name to put into the board
	colorName = getColorName(color);


	//go through and put the color name on the board
	for (i = 0; i < 3; i++)
		boardColors[i][startSpot] = colorName;
	boardColors[2][startSpot + 1] = colorName;

	return;
}


//function that will start the O block when it appears
void startOBlock(char boardColors[][10], int color, int &startSpot)
{
	char colorName;
	int i;

	//get a random number where the left end should start
	//make sure it is a number less than 8
	srand(time(NULL));

	//get random number between 0 and 8
	startSpot = rand() % 8;

	//call the color name function to get the name to put into the board
	colorName = getColorName(color);

	
	//loop through at add the other colors
	for (i = startSpot; i < startSpot + 2; i++)
		boardColors[0][i] = colorName;
	for (i = startSpot; i < startSpot + 2; i++)
		boardColors[1][i] = colorName;

	return;
}


//function that will start the S block when it appears
void startSBlock(char boardColors[][10], int color, int &startSpot)
{
	char colorName;
	int i;

	//get a random number where the left end should start
	//make sure it is a number less than 7
	srand(time(NULL));

	//get random number between 0 and 7
	startSpot = rand() % 7;

	//call the color name function to get the name to put into the board
	colorName = getColorName(color);


	//loop through at add the other colors
	for (i = startSpot + 1; i < startSpot + 3; i++)
		boardColors[0][i] = colorName;
	for (i = startSpot; i < startSpot + 2; i++)
		boardColors[1][i] = colorName;

	return;
}


//function that will start the T block when it appears
void startTBlock(char boardColors[][10], int color, int &startSpot)
{
	char colorName;
	int i;

	//get a random number where the left end should start
	//make sure it is a number less than 8
	srand(time(NULL));

	//get random number between 1 and 8
	startSpot = rand() % 7 + 1;

	//call the color name function to get the name to put into the board
	colorName = getColorName(color);


	//loop through at add the other colors
	boardColors[0][startSpot] = colorName;
	boardColors[1][startSpot - 1] = colorName;
	boardColors[1][startSpot] = colorName;
	boardColors[1][startSpot + 1] = colorName;

	return;
}


//function that will start the Z block when it appears
void startZBlock(char boardColors[][10], int color, int &startSpot)
{
	char colorName;
	int i;

	//get a random number where the left end should start
	//make sure it is a number less than 8
	srand(time(NULL));

	//get random number between 1 and 8
	startSpot = rand() % 8 + 1;

	//call the color name function to get the name to put into the board
	colorName = getColorName(color);


	//loop through at add the other colors
	boardColors[0][startSpot - 1] = colorName;
	boardColors[0][startSpot] = colorName;
	boardColors[1][startSpot] = colorName;
	boardColors[1][startSpot + 1] = colorName;
	

	return;
}

//function that will return the character name of what color will be used
char getColorName(int color)
{
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

	//light blue
	if (color == 9)
		return 76; //"L"
	//blue
	else if (color == 1)
		return 66; //"B"
	//magenta
	else if (color == 5)
		return 77; //"M"
	//yellow
	else if (color == 14)
		return 89; //"Y"
	//green
	else if (color == 2)
		return 71; //"G"
	//brown
	else if (color == 6)
		return 68; //"B"
	//red----- color == 4
	else 
		return 82; //"R"

}

