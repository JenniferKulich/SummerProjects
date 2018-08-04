#include "TBlock.h"

//3 is RIGHT
//1 is LEFT



//function that will move the first, upright, version of the T block to the left or right
void move1TBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the top block that sticks out


	//if the user move is 3, move the block to the right
	if (userMove == 3)
	{
		//check to see if can move to the right one
		if (startSpot <= 7)
		{
			boardColors[row][startSpot] = 00;
			boardColors[row][startSpot + 1] = colorName;
			boardColors[row + 1][startSpot - 1] = 00;
			boardColors[row + 1][startSpot + 2] = colorName;
			startSpot = startSpot + 1;
		}
	}


	//if the user move is 1, move the block to the left
	if (userMove == 1)
	{
		//check to see if can move to the left one
		if (startSpot >= 2)
		{
			boardColors[row][startSpot] = 00;
			boardColors[row][startSpot - 1] = colorName;
			boardColors[row + 1][startSpot + 1] = 00;
			boardColors[row + 1][startSpot - 2] = colorName;
			startSpot = startSpot - 1;
		}
	}

	return;
}


//function that will move the second, right facing, version of the T block to the left or right
void move2TBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the right most block that sticks out


	//if the user move is 3, move the block to the right
	if (userMove == 3)
	{
		//check to see if the move can be made to right
		if (startSpot <= 8)
		{
			boardColors[row - 1][startSpot - 1] = 00;
			boardColors[row - 1][startSpot] = colorName;
			boardColors[row][startSpot - 1] = 00;
			boardColors[row][startSpot + 1] = colorName;
			boardColors[row + 1][startSpot - 1] = 00;
			boardColors[row + 1][startSpot] = colorName;
			startSpot = startSpot + 1;
		}
	}

	//if the user move is 1, move the block to the left
	if (userMove == 1)
	{
		//check to see if the move can be made to the left
		if (startSpot >= 1)
		{
			boardColors[row - 1][startSpot - 1] = 00;
			boardColors[row - 1][startSpot - 2] = colorName;
			boardColors[row][startSpot] = 00;
			boardColors[row][startSpot - 2] = colorName;
			boardColors[row + 1][startSpot - 1] = 00;
			boardColors[row + 1][startSpot - 2] = colorName;
			startSpot = startSpot - 1;

		}

	}


	return;
}



//function that will move the third, downward, version of the T block to the left or right
void move3TBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the bottom most block that sticks down


	//if the user move is 3, move the block to the right
	if (userMove == 3)
	{
		//check if it can move over to the right
		if (startSpot <= 7)
		{
			boardColors[row - 1][startSpot - 1] = 00;
			boardColors[row - 1][startSpot + 2] = colorName;
			boardColors[row][startSpot] = 00;
			boardColors[row][startSpot + 1] = colorName;
			startSpot = startSpot + 1;
		}
	}

	//if the usre move is 1, move the block to the left
	if (userMove == 1)
	{
		//check if it can move over to the left
		if (startSpot >= 2)
		{
			boardColors[row - 1][startSpot + 1] = 00;
			boardColors[row - 1][startSpot - 2] = colorName;
			boardColors[row][startSpot] = 00;
			boardColors[row][startSpot - 1] = colorName;
			startSpot = startSpot - 1;
		}
	}


	return;
}


//function that will move the fourth, left facing, version of the T block to the left or right
void move4TBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the left most block that sticks out


	//if the user move is 3, move the block to the right
	if (userMove == 3)
	{
		//check to see if it can move one to the right
		if (startSpot <= 7)
		{
			boardColors[row - 1][startSpot + 1] = 00;
			boardColors[row - 1][startSpot + 2] = colorName;
			boardColors[row][startSpot] = 00;
			boardColors[row][startSpot + 2] = colorName;
			boardColors[row + 1][startSpot + 1] = 00;
			boardColors[row + 1][startSpot + 2] = colorName;
			startSpot = startSpot + 1;
		}
	}

	//if the user move is 1, move the block to the left
	if (userMove == 1)
	{
		//check to see if it can move to the left
		if (startSpot >= 1)
		{
			boardColors[row - 1][startSpot + 1] = 00;
			boardColors[row - 1][startSpot] = colorName;
			boardColors[row][startSpot + 1] = 00;
			boardColors[row][startSpot - 1] = colorName;
			boardColors[row + 1][startSpot + 1] = 00;
			boardColors[row + 1][startSpot] = colorName;
			startSpot = startSpot - 1;
		}
	}

	return;
}


//function that will turn the first, upward, version of T block clockwise to second version
void turn1TBlock(char boardColors[][10], char colorName, int &startSpot, int &row)
{
	bool canMove = true;

	//check to see if can turn block, turn it clockwise rotating on left side
	if (boardColors[row + 2][startSpot] != 00)
		canMove = false;

	//if can move is still true, turn the block
	if (canMove == true)
	{
		boardColors[row + 1][startSpot - 1] = 00;
		boardColors[row + 2][startSpot] = colorName;
		startSpot = startSpot + 1;
		row = row + 1;
		
	}

	return;
}


//function that will turn the second, right facing, version of T block clockwise to thrid version
void turn2TBlock(char boardColors[][10], char colorName, int &startSpot, int &row)
{
	bool canMove = true;

	//check to see if can turn block, turn it clockwise rotating on startSpot
	if (boardColors[row][startSpot - 2] != 00 && startSpot >= 1)
		canMove = false;

	//if can move is still true, turn the block
	if (canMove == true)
	{
		boardColors[row - 1][startSpot - 1] = 00;
		boardColors[row][startSpot - 2] = colorName;
		row = row + 1;
		startSpot = startSpot - 1;

	}
	
	return;
}


//function that will turn the third, downward, version of T block clockwise to fourth version
void turn3TBlock(char boardColors[][10], char colorName, int &startSpot, int &row)
{
	bool canMove = true;

	//check to see if can turn block, turn it clockwise rotating on startSpot
	if (boardColors[row - 2][startSpot] != 00 && row <= 1)
		canMove = false;

	//if can move is still true, turn the block
	if (canMove == true)
	{
		boardColors[row - 1][startSpot + 1] = 00;
		boardColors[row - 2][startSpot] = colorName;
		row = row - 1;
		startSpot = startSpot - 1;
	}


	return;
}


//function that will turn the fourth, left facing, version of T block clockwise to first position
void turn4TBlock(char boardColors[][10], char colorName, int &startSpot, int &row)
{
	bool canMove = true;


	//check to see if can turn block, turn it clockwise rotating on startSpot
	if (boardColors[row][startSpot + 2] != 0 && startSpot >= 8)
		canMove = false;

	//if can move is still true, turn the block
	if (canMove == true)
	{
		boardColors[row][startSpot + 2] = colorName;
		boardColors[row + 1][startSpot + 1] = 00;
		row = row - 1;
		startSpot = startSpot + 1;
	}

	return;
}


//function that will move the first, upright, version of T block down
void down1TBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	bool canMove = true;

	//check to see if can move down
	if (boardColors[row + 2][startSpot - 1] != 00 || boardColors[row + 2][startSpot] != 00
		|| boardColors[row + 2][startSpot + 1] != 00 || row == 19)
		canMove = false;
	

	//if cannot move down, set doneMoving to true
	if (canMove == false)
		doneMoving = true;

	//if can move down, then move down 
	if (canMove == true)
	{
		//move down
		boardColors[row + 1][startSpot - 1] = 00;
		boardColors[row + 2][startSpot - 1] = colorName;
		boardColors[row][startSpot] = 00;
		boardColors[row + 2][startSpot] = colorName;
		boardColors[row + 1][startSpot + 1] = 00;
		boardColors[row + 2][startSpot + 1] = colorName;
		row = row + 1;
		
		//check to see if the there's anything below it
		if (boardColors[row + 2][startSpot - 1] != 00 || boardColors[row + 2][startSpot] != 00
			|| boardColors[row + 2][startSpot + 1] != 00 || row == 19)
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


//function that will move the second, right facing, version of T block down
void down2TBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	bool canMove = true;

	//check to see if can move down
	if (boardColors[row + 2][startSpot - 1] != 00 || boardColors[row + 1][startSpot] != 00
		|| row + 1 == 19)
		canMove = false;


	//if cannot move down, set doneMoving to true
	if (canMove == false)
		doneMoving = true;

	//if can move down, then move down 
	if (canMove == true)
	{
		//move down
		boardColors[row - 1][startSpot - 1] = 00;
		boardColors[row + 2][startSpot - 1] = colorName;
		boardColors[row][startSpot] = 00;
		boardColors[row + 1][startSpot] = colorName;
		row = row + 1;

		//check to see if the there's anything below it
		if (boardColors[row + 2][startSpot - 1] != 00 || boardColors[row + 1][startSpot] != 00
			|| row + 1 == 19)
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


//function that will move the thrid, downward, version of T block down
void down3TBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	bool canMove = true;

	//check to see if can move down
	if (boardColors[row - 1][startSpot - 1] != 00 || boardColors[row - 1][startSpot + 1] != 0 
		|| boardColors[row + 1][startSpot] != 00 || row == 19)
		canMove = false;


	//if cannot move down, set doneMoving to true
	if (canMove == false)
		doneMoving = true;

	//if can move down, then move down 
	if (canMove == true)
	{
		//move down
		boardColors[row - 1][startSpot - 1] = 00;
		boardColors[row][startSpot - 1] = colorName;
		boardColors[row - 1][startSpot] = 00;
		boardColors[row - 1][startSpot + 1] = 00;
		boardColors[row][startSpot + 1] = colorName;
		boardColors[row + 1][startSpot] = colorName;
		row = row + 1;
	

		//check to see if the there's anything below it
		if (boardColors[row - 1][startSpot - 1] != 00 || boardColors[row - 1][startSpot + 1] != 0
			|| boardColors[row + 1][startSpot] != 00 || row == 19)
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


//function that will move the fourth, left facing, version of T block down
void down4TBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	bool canMove = true;

	//check to see if can move down
	if ( boardColors[row + 1][startSpot] != 00 || boardColors[row + 2][startSpot + 1] != 00
		|| row + 1 == 19)
		canMove = false;


	//if cannot move down, set doneMoving to true
	if (canMove == false)
		doneMoving = true;

	//if can move down, then move down 
	if (canMove == true)
	{
		//move down
		boardColors[row - 1][startSpot + 1] = 00;
		boardColors[row + 2][startSpot + 1] = colorName;
		boardColors[row][startSpot] = 00;
		boardColors[row + 1][startSpot] = colorName;
		row = row + 1;


		//check to see if the there's anything below it
		if (boardColors[row + 1][startSpot] != 00 || boardColors[row + 2][startSpot + 1] != 00
			|| row + 1 == 19)
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
