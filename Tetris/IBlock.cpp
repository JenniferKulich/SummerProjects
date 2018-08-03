#include "IBlock.h"

//3 is RIGHT
//1 is LEFT
//6 is CLOCKWISE


//function that will move the horizontal I block left, or right
void moveHorizontalIBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the very left block

	//if the user move is 3, the block will go to the right once
	if (userMove == 3)
	{
		//check to make sure the block can move to the right one
		if (startSpot + 3 <= 9)
		{
			boardColors[row][startSpot] = 00;
			boardColors[row][startSpot + 4] = colorName;
			startSpot = startSpot + 1;
		}

	}

	//if the user move is 1, the block will go to the left once
	if (userMove == 1)
	{
		//check to make sure the block can move to the left one
		if (startSpot - 1 >= 0)
		{
			boardColors[row][startSpot + 3] = 00;
			boardColors[row][startSpot - 1] = colorName;
			startSpot = startSpot - 1;
		}

	}

	
	return;
}


//function that will move the vertical I block left, or right
void moveVerticalIBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the very top block
	int i;

	//if user move is 3, check to move all to the right
	if (userMove == 3)
	{
		if (startSpot < 9)
		{
			//loop through to move all over
			for (i = row; i < row + 3; i++)
			{
				boardColors[i][startSpot] = 00;
				boardColors[i][startSpot + 1] = colorName;
				startSpot = startSpot + 1;

			}
		}
	}


	//if user move is 1, check to move all to the left
	if (userMove == 1)
	{
		if (startSpot > 0)
		{
			//loop through to move all over
			for (i = row; i < row + 3; i++)
			{
				boardColors[i][startSpot] = 00;
				boardColors[i][startSpot - 1] = colorName;
				startSpot = startSpot - 1;

			}
		}
	}

	return;
}


//function that will turn the horizontal block 
void turnHorizontalIBlock(char boardColors[][10], char colorName, int &startSpot, int row)
{
	int i;
	int newRow = 0;
	bool canMove = true;

	//check to see if can turn block, turn it clockwise rotating on left side 
	for (i = row + 1; i < row + 4; i++)
	{
		if (boardColors[i][startSpot] != 00)
			canMove = false;
	}

	//if can move is still true, turn the block
	if (canMove == true)
	{
		newRow = row;
		for (i = startSpot + 1; i < startSpot + 4; i++)
		{
			boardColors[row][i] = 00;
			boardColors[newRow + 1][startSpot] = colorName;
			newRow = newRow + 1;
		}
	}

	return;
}


//function that will turn the horizontal block
void turnVerticalIBlock(char boardColors[][10], char colorName, int &startSpot, int row)
{
	int i;
	int newRow = 0;
	bool canMove = true;

	
	//check to see if can turn block, turn it clockwise rotating on top side 
	if (startSpot <= 6)
	{
		//go through to check that there's nothing there
		for (i = startSpot + 1; i < startSpot + 4; i++)
		{
			if (boardColors[row][i] != 00)
				canMove = false;
		}
	}

	//if can move is still true, turn the block
	if (canMove == true)
	{
		newRow = row;
		for (i = startSpot + 1; i < startSpot + 4; i++)
		{
			boardColors[row][i] = colorName;
			boardColors[newRow + 1][startSpot] = 00;
			newRow = newRow + 1;
		}
	}

	return;
}


//function that will move the horizontal I block down one and check if it is in the final resting position
void downHorizontalIBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	int i;
	bool canMove = true;

	//loop through and check to see if can move down
	for (i = startSpot; i < startSpot + 4; i++)
	{
		if (boardColors[row + 1][i] != 00)
			canMove = false;
	}
	if (row == 19)
		canMove = false;

	//if cannot move down, set doneMoving to true
	if (canMove == false)
		doneMoving = true;

	//if can move down, then move down 
	if (canMove == true)
	{
		for (i = startSpot; i < startSpot + 4; i++)
		{
			boardColors[row][i] = 00;
			boardColors[row + 1][i] = colorName;
		}
		row = row + 1;

		//check to see if the there's anything below it
		for (i = startSpot; i < startSpot + 4; i++)
		{
			if (boardColors[row][i] != 00)
				canMove = false;
		}
		if (row == 19)
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


//function that will move the vertical I block down one and check if it is in the final resting position
void downVerticalIBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	int i;
	bool canMove = true;

	//check to see if can move down
	if (boardColors[row + 4][startSpot] != 00 || row == 19)
		canMove = false;

	//if cannot move down, set doneMoving to true
	if (canMove == false)
		doneMoving = true;

	//if can move down, then move down 
	if (canMove == true)
	{
		boardColors[row][startSpot] = 00;
		boardColors[row + 4][startSpot] = colorName;
		row = row + 1;

		//check to see if the there's anything below it
		if (boardColors[row + 4][startSpot] != 00 || row == 19)
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