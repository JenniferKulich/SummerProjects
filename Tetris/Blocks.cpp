#include "Blocks.h"

//where the functions are written


//function that will start the I block when it appears
void startIBlock(char boardColors[][10], int colorName, int &startSpot)
{
	int i;

	//get a random number where the left end should start
	//make sure it is a number less than 6
	srand(time(NULL));

	//get random number between 0 and 6
	startSpot = rand() % 6;

	
	//loop through to put the color name on to the board
	for (i = startSpot; i < startSpot + 4; i++)
		boardColors[0][i] = colorName;


	return;
}


//function that will start the J block when it appears 
void startJBlock(char boardColors[][10], int colorName, int &startSpot)
{
	int i;

	//get a random number where the left end should start
	//make sure it is a number less than 8
	srand(time(NULL));

	//get random number between 1 and 8
	startSpot = rand() % 8 + 1;

	

	//go through and put the color name on the board
	for (i = 0; i < 3; i++ )
		boardColors[i][startSpot] = colorName;
	boardColors[2][startSpot - 1] = colorName;


	return;
}


//function that will start the L block when it appears
void startLBlock(char boardColors[][10], int colorName, int &startSpot)
{
	int i;

	//get a random number where the left end should start
	//make sure it is a number less than 8
	srand(time(NULL));

	//get random number between 0 and 8
	startSpot = rand() % 8;

	
	//go through and put the color name on the board
	for (i = 0; i < 3; i++)
		boardColors[i][startSpot] = colorName;
	boardColors[2][startSpot + 1] = colorName;

	return;
}


//function that will start the O block when it appears
void startOBlock(char boardColors[][10], int colorName, int &startSpot)
{
	int i;

	//get a random number where the left end should start
	//make sure it is a number less than 8
	srand(time(NULL));

	//get random number between 0 and 8
	startSpot = rand() % 8;

	
	//loop through at add the other colors
	for (i = startSpot; i < startSpot + 2; i++)
		boardColors[0][i] = colorName;
	for (i = startSpot; i < startSpot + 2; i++)
		boardColors[1][i] = colorName;

	return;
}


//function that will start the S block when it appears
void startSBlock(char boardColors[][10], int colorName, int &startSpot)
{
	int i;

	//get a random number where the left end should start
	//make sure it is a number less than 9
	srand(time(NULL));

	//get random number between 1 and 8
	startSpot = rand() % 8 + 1;

	
	//loop through at add the other colors
	boardColors[0][startSpot] = colorName;
	boardColors[0][startSpot + 1] = colorName;
	boardColors[1][startSpot] = colorName;
	boardColors[1][startSpot - 1] = colorName;

	return;
}


//function that will start the T block when it appears
void startTBlock(char boardColors[][10], int colorName, int &startSpot)
{
	int i;

	//get a random number where the left end should start
	//make sure it is a number less than 8
	srand(time(NULL));

	//get random number between 1 and 8
	startSpot = rand() % 8 + 1;

	
	//loop through at add the other colors
	boardColors[0][startSpot] = colorName;
	boardColors[1][startSpot - 1] = colorName;
	boardColors[1][startSpot] = colorName;
	boardColors[1][startSpot + 1] = colorName;

	return;
}


//function that will start the Z block when it appears
void startZBlock(char boardColors[][10], int colorName, int &startSpot)
{
	int i;

	//get a random number where the left end should start
	//make sure it is a number less than 8
	srand(time(NULL));

	//get random number between 1 and 8
	startSpot = rand() % 8 + 1;

	
	//loop through at add the other colors
	boardColors[0][startSpot - 1] = colorName;
	boardColors[0][startSpot] = colorName;
	boardColors[1][startSpot] = colorName;
	boardColors[1][startSpot + 1] = colorName;
	

	return;
}


