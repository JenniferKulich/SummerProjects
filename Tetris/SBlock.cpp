#include "SBlock.h"

//3 is RIGHT
//1 is LEFT

//function that will move right facing S block to the right or left
void move1SBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the top middle block of normal S


	//if the user move is 3, move the block to the right
	if (userMove == 3)
	{
		//check to see if can move to the right one
		if (startSpot <= 7 && boardColors[row][startSpot + 2] == 00 &&
		boardColors[row + 1][startSpot + 1] == 00)
		{
			boardColors[row][startSpot] = 00;
			boardColors[row + 1][startSpot - 1] = 00;
			boardColors[row][startSpot + 2] = colorName;
			boardColors[row + 1][startSpot + 1] = colorName;
			startSpot = startSpot + 1;
		}
	}

	//if the user move is 1, move the block to the left
	if (userMove == 1)
	{
		//check to see if can move to the left one
		if (startSpot >= 2 && boardColors[row][startSpot - 1] == 00 &&
		boardColors[row + 1][startSpot - 2] == 00)
		{
			boardColors[row][startSpot + 1] = 00;
			boardColors[row + 1][startSpot] = 00;
			boardColors[row][startSpot - 1] = colorName;
			boardColors[row + 1][startSpot - 2] = colorName;
			startSpot = startSpot - 1;
		}
	}

	return;
}


//function that will move the down facing S block to the right or left
void move2SBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the top middle block of normal S


	//if the user move is 3, move the block to the right
	if (userMove == 3)
	{
		//check to see if can move to the right one
		if (startSpot <= 7 && boardColors[row - 1][startSpot + 1] == 00 &&
		boardColors[row + 1][startSpot + 2] == 00 &&
		boardColors[row][startSpot + 2] == 00)
		{
			boardColors[row - 1][startSpot] = 00;
			boardColors[row][startSpot] = 00;
			boardColors[row + 1][startSpot + 1] = 00;
			boardColors[row - 1][startSpot + 1] = colorName;
			boardColors[row + 1][startSpot + 2] = colorName;
			boardColors[row][startSpot + 2] = colorName;
			startSpot = startSpot + 1;
		}
	}

	//WORKING HERE
	//if the user move is 1, move the block to the left
	if (userMove == 1)
	{
		//check to see if can move to the left one
		if (startSpot >= 1 && boardColors[row - 1][startSpot - 1] == 00 &&
		boardColors[row][startSpot - 1] == 00 &&
		boardColors[row + 1][startSpot] == 00)
		{
			boardColors[row - 1][startSpot] = 00;
			boardColors[row][startSpot + 1] = 00;
			boardColors[row + 1][startSpot + 1] = 00;
			boardColors[row - 1][startSpot - 1] = colorName;
			boardColors[row][startSpot - 1] = colorName;
			boardColors[row + 1][startSpot] = colorName;
			startSpot = startSpot - 1;
		}
	}

	return;
}


//function that will turn the right facing S block to the down facing block
void turn1SBlock(char boardColors[][10], char colorName, int &startSpot, int &row)
{
	bool canMove = true;


	//check to see if can turn block, turn it clockwise rotating on startSpot
	if (boardColors[row + 1][startSpot + 1] != 00 || boardColors[row - 1][startSpot] != 00)
		canMove = false;

	//if can move is still true, turn the block
	if (canMove == true)
	{
		boardColors[row + 1][startSpot - 1] = 00;
		boardColors[row + 1][startSpot] = 00;
		boardColors[row - 1][startSpot] = colorName;
		boardColors[row + 1][startSpot + 1] = colorName;

	}

	return;
}


//function that will turn the down facing S block to the right facing S block
void turn2SBlock(char boardColors[][10], char colorName, int &startSpot, int &row)
{
	bool canMove = true;


	//check to see if can turn block, turn it clockwise rotating on startSpot
	if (boardColors[row + 1][startSpot] != 00 ||
	boardColors[row + 1][startSpot - 1] != 00)
		canMove = false;

	//if can move is still true, turn the block
	if (canMove == true)
	{
		boardColors[row - 1][startSpot] = 00;
		boardColors[row + 1][startSpot + 1] = 00;
		boardColors[row + 1][startSpot] = colorName;
		boardColors[row + 1][startSpot - 1] = colorName;

	}

	return;
}


//function that will move the right facing S block down
void down1SBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	bool canMove = true;

	//check to see if can move down
	if (row + 1 == 19 || boardColors[row + 1][startSpot + 1] != 00 ||
		boardColors[row + 2][startSpot] != 00 || boardColors[row + 2][startSpot - 1] != 00)
		canMove = false;


	//if cannot move down, set doneMoving to true
	if (canMove == false)
		doneMoving = true;

	//if can move down, then move down 
	if (canMove == true)
	{
		//move down
		boardColors[row][startSpot] = 00;
		boardColors[row][startSpot + 1] = 00;
		boardColors[row + 1][startSpot - 1] = 00;
		boardColors[row + 1][startSpot + 1] = colorName;
		boardColors[row + 2][startSpot - 1] = colorName;
		boardColors[row + 2][startSpot] = colorName;
		row = row + 1;

		//check to see if the there's anything below it
		if (row + 1 == 19 || boardColors[row + 1][startSpot + 1] != 00 ||
			boardColors[row + 2][startSpot] != 00 || boardColors[row + 2][startSpot - 1] != 00)
			canMove = false;

		//if there's something below it, will not move any more, and doneMoving will be true
		if (canMove == false)
			doneMoving = true;

		//if nothing below it, set doneMoving to false
		else
			doneMoving = false;
	}

	return;
}


//function that will move the down facing S block down
void down2SBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	bool canMove = true;

	//check to see if can move down
	if (row + 1 == 19 || boardColors[row + 1][startSpot] != 00 ||
		boardColors[row + 2][startSpot + 1] != 00)
		canMove = false;


	//if cannot move down, set doneMoving to true
	if (canMove == false)
		doneMoving = true;

	//if can move down, then move down 
	if (canMove == true)
	{
		//move down
		boardColors[row - 1][startSpot] = 00;
		boardColors[row][startSpot + 1] = 00;
		boardColors[row + 1][startSpot] = colorName;
		boardColors[row + 2][startSpot + 1] = colorName;
		row = row + 1;

		//check to see if the there's anything below it
		if (row + 1 == 19 || boardColors[row + 1][startSpot] != 00 ||
			boardColors[row + 2][startSpot + 1] != 00)
			canMove = false;

		//if there's something below it, will not move any more, and doneMoving will be true
		if (canMove == false)
			doneMoving = true;

		//if nothing below it, set doneMoving to false
		else
			doneMoving = false;
	}

	return;
}
