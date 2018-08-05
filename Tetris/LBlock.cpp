#include "LBlock.h"

//3 is RIGHT
//1 is LEFT

//function that will move the first L block, normal L, to the right or left
void move1LBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the corner block


	//if the user move is 3, move the block to the right
	if (userMove == 3)
	{
		//check to see if can move to the right one
		if (startSpot <= 7 && boardColors[row - 2][startSpot + 1] == 00 &&
			boardColors[row - 1][startSpot + 1] == 00 && boardColors[row][startSpot + 2] == 00)
		{
			boardColors[row - 2][startSpot] = 00;
			boardColors[row - 2][startSpot + 1] = colorName;
			boardColors[row - 1][startSpot] = 00;
			boardColors[row - 1][startSpot + 1] = colorName;
			boardColors[row][startSpot] = 00;
			boardColors[row][startSpot + 2] = colorName;
			startSpot = startSpot + 1;
		}
	}

	//if the user move is 1, move the block to the left
	if (userMove == 1)
	{
		//check to see if can move to the left one
		if (startSpot >= 1 && boardColors[row - 2][startSpot - 1] == 00 &&
			boardColors[row - 1][startSpot - 1] == 00 && boardColors[row][startSpot - 1] == 00)
		{
			boardColors[row - 2][startSpot] = 00;
			boardColors[row - 2][startSpot - 1] = colorName;
			boardColors[row - 1][startSpot] = 00;
			boardColors[row - 1][startSpot - 1] = colorName;
			boardColors[row][startSpot + 1] = 00;
			boardColors[row][startSpot - 1] = colorName;
			startSpot = startSpot - 1;
		}
	}

	return;
}


//function that will move the second L block, downward L, to the right or left
void move2LBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the corner block


	//if the user move is 3, move the block to the right
	if (userMove == 3)
	{
		//check to see if can move to the right one
		if (startSpot <= 6 && boardColors[row][startSpot + 3] == 00 &&
			boardColors[row + 1][startSpot + 1] == 00)
		{
			boardColors[row][startSpot] = 00;
			boardColors[row][startSpot + 3] = colorName;
			boardColors[row + 1][startSpot] = 00;
			boardColors[row + 1][startSpot + 1] = colorName;
			startSpot = startSpot + 1;
		}
	}

	//if the user move is 1, move the block to the left
	if (userMove == 1)
	{
		//check to see if can move to the left one
		if (startSpot >= 1 && boardColors[row][startSpot - 1] == 00 &&
			boardColors[row + 1][startSpot - 1] == 00)
		{
			boardColors[row][startSpot + 2] = 00;
			boardColors[row][startSpot - 1] = colorName;
			boardColors[row + 1][startSpot] = 00;
			boardColors[row + 1][startSpot - 1] = colorName;
			startSpot = startSpot - 1;
		}
	}


	return;
}


//function that will move the third L block, backwards L, to the right or left
void move3LBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the corner block


	//if the user move is 3, move the block to the right
	if (userMove == 3)
	{
		//check to see if can move to the right one
		if (startSpot <= 8 && boardColors[row][startSpot + 1] == 00 &&
			boardColors[row + 1][startSpot + 1] == 00 && boardColors[row + 2][startSpot + 1] == 00)
		{
			boardColors[row][startSpot - 1] = 00;
			boardColors[row][startSpot + 1] = colorName;
			boardColors[row + 1][startSpot] = 00;
			boardColors[row + 1][startSpot + 1] = colorName;
			boardColors[row + 2][startSpot] = 00;
			boardColors[row + 2][startSpot + 1] = colorName;
			startSpot = startSpot + 1;
		}
	}

	//if the user move is 1, move the block to the left
	if (userMove == 1)
	{
		//check to see if can move to the left one
		if (startSpot >= 2 && boardColors[row][startSpot - 2] == 00 &&
			boardColors[row + 1][startSpot - 1] == 00 && boardColors[row + 2][startSpot - 1] == 00)
		{
			boardColors[row][startSpot] = 00;
			boardColors[row][startSpot - 2] = colorName;
			boardColors[row + 1][startSpot] = 00;
			boardColors[row + 1][startSpot - 1] = colorName;
			boardColors[row + 2][startSpot] = 00;
			boardColors[row + 2][startSpot - 1] = colorName;
			startSpot = startSpot - 1;
		}
	}

	return;
}


//function that will move the fourth L block, upward L, to the right or left
void move4LBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the corner block


	//if the user move is 3, move the block to the right
	if (userMove == 3)
	{
		//check to see if can move to the right one
		if (startSpot <= 8 && boardColors[row - 1][startSpot + 1] == 00 &&
			boardColors[row][startSpot + 1] == 00)
		{
			boardColors[row - 1][startSpot] = 00;
			boardColors[row - 1][startSpot + 1] = colorName;
			boardColors[row][startSpot - 2] = 00;
			boardColors[row][startSpot + 1] = colorName;
			startSpot = startSpot + 1;
		}
	}

	//if the user move is 1, move the block to the left
	if (userMove == 1)
	{
		//check to see if can move to the left one
		if (startSpot >= 3 && boardColors[row - 1][startSpot - 1] == 00 &&
			boardColors[row][startSpot - 3] == 00)
		{
			boardColors[row - 1][startSpot] = 00;
			boardColors[row - 1][startSpot - 1] = colorName;
			boardColors[row][startSpot] = 00;
			boardColors[row][startSpot - 3] = colorName;
			startSpot = startSpot - 1;
		}
	}

	return;
}


//function that will turn the normal L block to downwards L block
void turn1LBlock(char boardColors[][10], char colorName, int &startSpot, int &row)
{
	bool canMove = true;

	//check to see if can turn block, turn it clockwise rotating on left side
	if (startSpot < 1 || boardColors[row - 1][startSpot - 1] != 0 ||
		boardColors[row][startSpot - 1] != 00 || boardColors[row - 1][startSpot + 1] != 00)
		canMove = false;

	//if can move is still true, turn the block
	if (canMove == true)
	{
		//rotate on middle up and down block
		boardColors[row - 2][startSpot] = 00;
		boardColors[row - 1][startSpot + 1] = colorName;
		boardColors[row][startSpot] = 00;
		boardColors[row - 1][startSpot - 1] = colorName;
		boardColors[row][startSpot + 1] = 00;
		boardColors[row][startSpot - 1] = colorName;
		row = row - 1;
		startSpot = startSpot - 1;
	}


	return;
}


//function that will turn downwards L block to left facing L block
void turn2LBlock(char boardColors[][10], char colorName, int &startSpot, int &row)
{
	bool canMove = true;

	//check to see if can turn block, turn it clockwise rotating on left side
	if (boardColors[row + 1][startSpot + 1] != 00 || boardColors[row - 1][startSpot] != 00 
		|| boardColors[row - 1][startSpot - 1] != 00)
		canMove = false;

	//if can move is still true, turn the block
	if (canMove == true)
	{
		//rotate on middle up and down block
		boardColors[row][startSpot + 2] = 00;
		boardColors[row + 1][startSpot + 1] = colorName;
		boardColors[row][startSpot] = 00;
		boardColors[row - 1][startSpot + 1] = colorName;
		boardColors[row + 1][startSpot] = 00;
		boardColors[row - 1][startSpot] = colorName;
		row = row - 1;
		startSpot = startSpot + 1;
	}

	return;
}


//function that will turn left facing L block to up facing L block
void turn3LBlock(char boardColors[][10], char colorName, int &startSpot, int &row)
{
	bool canMove = true;

	//check to see if can turn block, turn it clockwise rotating on left side
	if (startSpot == 9 || boardColors[row][startSpot + 1] != 00 || boardColors[row + 1][startSpot + 1] != 00
		|| boardColors[row + 1][startSpot - 1] != 00)
		canMove = false;

	//if can move is still true, turn the block
	if (canMove == true)
	{
		//rotate on middle up and down block
		boardColors[row][startSpot - 1] = 00;
		boardColors[row][startSpot] = 00;
		boardColors[row][startSpot + 1] = colorName;
		boardColors[row + 2][startSpot] = 00;
		boardColors[row + 1][startSpot + 1] = colorName;
		boardColors[row + 1][startSpot - 1] = colorName;
		row = row + 1;
		startSpot = startSpot + 1;
	}


	return;
}


//function that will turn up facing L block to normal facing L block
void turn4LBlock(char boardColors[][10], char colorName, int &startSpot, int &row)
{
	bool canMove = true;

	//check to see if can turn block, turn it clockwise rotating on left side
	if (startSpot >= 8 || boardColors[row + 1][startSpot] != 00 || boardColors[row + 1][startSpot + 1] != 00)
		canMove = false;

	//if can move is still true, turn the block
	if (canMove == true)
	{
		//rotate on middle up and down block
		boardColors[row - 1][startSpot] = 00;
		boardColors[row][startSpot] = 00;
		boardColors[row][startSpot - 2] = 00;
		boardColors[row + 1][startSpot - 1] = colorName;
		boardColors[row + 1][startSpot] = colorName;
		boardColors[row - 1][startSpot - 1] = colorName;
		row = row + 1;
		startSpot = startSpot - 1;
 	}

	return;
}


//function that will move normal facing L down 
void down1LBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	bool canMove = true;

	//check to see if can move down
	if (boardColors[row + 1][startSpot] != 00 || boardColors[row + 1][startSpot + 1] != 00|| row == 19)
		canMove = false;


	//if cannot move down, set doneMoving to true
	if (canMove == false)
		doneMoving = true;

	//if can move down, then move down 
	if (canMove == true)
	{
		//move down
		boardColors[row][startSpot + 1] = 00;
		boardColors[row + 1][startSpot + 1] = colorName;
		boardColors[row - 2][startSpot] = 00;
		boardColors[row + 1][startSpot] = colorName;
		row = row + 1;

		//check to see if the there's anything below it
		if (boardColors[row + 1][startSpot] != 00 || boardColors[row + 1][startSpot + 1] != 00 || row == 19)
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


//function that will move downward facing L down
void down2LBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	bool canMove = true;

	//check to see if can move down
	if (boardColors[row + 2][startSpot] != 00 || boardColors[row + 1][startSpot + 1] != 00 ||
		boardColors[row + 1][startSpot + 2] != 00 || row + 1 == 19)
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
		boardColors[row][startSpot + 2] = 00;
		boardColors[row + 1][startSpot + 1] = colorName;
		boardColors[row + 1][startSpot + 2] = colorName;
		boardColors[row + 2][startSpot] = colorName;
		row = row + 1;

		//check to see if the there's anything below it
		if (boardColors[row + 2][startSpot] != 00 || boardColors[row + 1][startSpot + 1] != 00 ||
			boardColors[row + 1][startSpot + 2] != 00 || row + 1 == 19)
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


//function that will move left facing L down
void down3LBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	bool canMove = true;

	//check to see if can move down
	if (row + 2 == 19 || boardColors[row + 1][startSpot - 1] != 00
		|| boardColors[row + 3][startSpot] != 00 )
		canMove = false;


	//if cannot move down, set doneMoving to true
	if (canMove == false)
		doneMoving = true;

	//if can move down, then move down 
	if (canMove == true)
	{
		//move down
		boardColors[row][startSpot - 1] = 00;
		boardColors[row][startSpot] = 00;
		boardColors[row + 1][startSpot - 1] = colorName;
		boardColors[row + 3][startSpot] = colorName;
		row = row + 1;

		//check to see if the there's anything below it
		if (row + 2 == 19 || boardColors[row + 1][startSpot - 1] != 00
			|| boardColors[row + 3][startSpot] != 00)
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


//function that will move up facing L down
void down4LBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	bool canMove = true;

	//check to see if can move down
	if (row == 19 || boardColors[row + 1][startSpot] != 00 ||
		boardColors[row + 1][startSpot - 1] != 00 || boardColors[row + 1][startSpot - 2] != 00)
		canMove = false;


	//if cannot move down, set doneMoving to true
	if (canMove == false)
		doneMoving = true;

	//if can move down, then move down 
	if (canMove == true)
	{
		//move down
		boardColors[row - 1][startSpot] = 00;
		boardColors[row][startSpot - 1] = 00;
		boardColors[row][startSpot - 2] = 00;
		boardColors[row + 1][startSpot - 1] = colorName;
		boardColors[row + 1][startSpot - 2] = colorName;
		boardColors[row + 1][startSpot] = colorName;
		row = row + 1;

		//check to see if the there's anything below it
		if (row == 19 || boardColors[row + 1][startSpot] != 00 ||
			boardColors[row + 1][startSpot - 1] != 00 || boardColors[row + 1][startSpot - 2] != 00)
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