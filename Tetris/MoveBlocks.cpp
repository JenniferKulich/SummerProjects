#include "MoveBlocks.h"

//3 is RIGHT
//1 is LEFT


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