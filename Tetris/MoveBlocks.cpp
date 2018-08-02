#include "MoveBlocks.h"

//3 is RIGHT
//1 is LEFT

//function that will move the horizontal I block down, left, or right
void moveHorizontalIBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the very left block
	int i;

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