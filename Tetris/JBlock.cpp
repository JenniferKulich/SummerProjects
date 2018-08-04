#include "JBlock.h"

//3 is RIGHT
//1 is LEFT

//function that will move the normal, left facing, J block right or left
void move1JBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the middle up and down block


	//if the user move is 3, move the block to the right
	if (userMove == 3)
	{
		//check to see if can move to the right one
		if (startSpot <= 8)
		{
			boardColors[row - 1][startSpot] = 00;
			boardColors[row][startSpot] = 00;
			boardColors[row + 1][startSpot - 1] = 00;
			boardColors[row - 1][startSpot + 1] = colorName;
			boardColors[row][startSpot + 1] = colorName;
			boardColors[row + 1][startSpot + 1] = colorName;
			startSpot = startSpot + 1;
		}
	}

	//if the user move is 1, move the block to the left
	if (userMove == 1)
	{
		//check to see if can move to the left one
		if (startSpot >= 2)
		{
			boardColors[row - 1][startSpot] = 00;
			boardColors[row][startSpot] = 00;
			boardColors[row + 1][startSpot] = 00;
			boardColors[row - 1][startSpot - 1] = colorName;
			boardColors[row][startSpot - 1] = colorName;
			boardColors[row + 1][startSpot - 2] = colorName;
			startSpot = startSpot - 1;
		}
	}

	return;
}


//function that will move the second, up facing, J block right or left
void move2JBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the middle up and down block


	//if the user move is 3, move the block to the right
	if (userMove == 3)
	{
		//check to see if can move to the right one
		if (startSpot <= 7)
		{
			boardColors[row - 1][startSpot - 1] = 00;
			boardColors[row][startSpot - 1] = 00;
			boardColors[row][startSpot + 2] = colorName;
			boardColors[row - 1][startSpot] = colorName;
			startSpot = startSpot + 1;
		}
	}

	//if the user move is 1, move the block to the left
	if (userMove == 1)
	{
		//check to see if can move to the left one
		if (startSpot >= 2)
		{
			boardColors[row - 1][startSpot - 1] = 00;
			boardColors[row][startSpot + 1] = 00;
			boardColors[row - 1][startSpot - 2] = colorName;
			boardColors[row][startSpot - 2] = colorName;
			startSpot = startSpot - 1;
		}
	}

	return;
}


//function that will move the third, right facing, J block right or left
void move3JBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the middle up and down block


	//if the user move is 3, move the block to the right
	if (userMove == 3)
	{
		//check to see if can move to the right one
		if (startSpot <= 7)
		{
			boardColors[row - 1][startSpot] = 00;
			boardColors[row][startSpot] = 00;
			boardColors[row + 1][startSpot] = 00;
			boardColors[row - 1][startSpot + 2] = colorName;
			boardColors[row][startSpot + 1] = colorName;
			boardColors[row + 1][startSpot + 1] = colorName;
 			startSpot = startSpot + 1;
		}
	}

	//if the user move is 1, move the block to the left
	if (userMove == 1)
	{
		//check to see if can move to the left one
		if (startSpot >= 1)
		{
			boardColors[row - 1][startSpot + 1] = 00;
			boardColors[row][startSpot] = 00;
			boardColors[row + 1][startSpot] = 0;
			boardColors[row - 1][startSpot - 1] = colorName;
			boardColors[row][startSpot - 1] = colorName;
			boardColors[row + 1][startSpot - 1] = colorName;
			startSpot = startSpot - 1;
		}
	}

	return;
}


//function that will move the fourth, down facing, J block right or left
void move4JBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row)
{
	//start spot is the middle up and down block


	//if the user move is 3, move the block to the right
	if (userMove == 3)
	{
		//check to see if can move to the right one
		if (startSpot <= 7)
		{
			boardColors[row][startSpot - 1] = 00;
			boardColors[row + 1][startSpot + 1] = 00;
			boardColors[row][startSpot + 2] = colorName;
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
			boardColors[row][startSpot + 1] = 00;
			boardColors[row + 1][startSpot + 1] = 00;
			boardColors[row][startSpot - 2] = colorName;
			boardColors[row + 1][startSpot] = colorName;

			startSpot = startSpot - 1;
		}
	}

	return;
}


//function that will turn the normal J block to the up facing block
void turn1JBlock(char boardColors[][10], char colorName, int &startSpot, int &row)
{
	bool canMove = true;

	//check to see if can turn block, turn it clockwise rotating on left side
	if (boardColors[row][startSpot - 1] != 00 || boardColors[row - 1][startSpot - 1] != 00 
		|| boardColors[row][startSpot + 1] != 00)
		canMove = false;

	//if can move is still true, turn the block
	if (canMove == true)
	{
		//rotate on middle up and down block
		boardColors[row + 1][startSpot] = 00;
		boardColors[row + 1][startSpot - 1] = 00;
		boardColors[row - 1][startSpot] = 00;
		boardColors[row - 1][startSpot - 1] = colorName;
		boardColors[row][startSpot - 1] = colorName;
		boardColors[row][startSpot + 1] = colorName;
	}

	return;
}


//function that will turn the up facing J block to the right facing J block
void turn2JBlock(char boardColors[][10], char colorName, int &startSpot, int &row)
{
	bool canMove = true;

	//check to see if can turn block, turn it clockwise rotating on left side
	if (boardColors[row - 1][startSpot] != 00 || boardColors[row - 1][startSpot + 1] != 00
		|| boardColors[row + 1][startSpot] != 00)
		canMove = false;

	//if can move is still true, turn the block
	if (canMove == true)
	{
		//rotate on middle up and down block
		boardColors[row - 1][startSpot - 1] = 00;
		boardColors[row][startSpot - 1] = 00;
		boardColors[row][startSpot + 1] = 00;
		boardColors[row - 1][startSpot] = colorName;
		boardColors[row - 1][startSpot + 1] = colorName;
		boardColors[row + 1][startSpot] = colorName;
	}

	return;
}


//function that will turn the right facing J block to the down facing J block
void turn3JBlock(char boardColors[][10], char colorName, int &startSpot, int &row)
{
	bool canMove = true;

	//check to see if can turn block, turn it clockwise rotating on left side
	if (boardColors[row + 1][startSpot + 1] != 00 || boardColors[row][startSpot + 1] != 00
		|| boardColors[row][startSpot - 1] != 00)
		canMove = false;

	//if can move is still true, turn the block
	if (canMove == true)
	{
		//rotate on middle up and down block
		boardColors[row - 1][startSpot] = 00;
		boardColors[row - 1][startSpot + 1] = 00;
		boardColors[row + 1][startSpot] = 00;
		boardColors[row][startSpot + 1] = colorName;
		boardColors[row + 1][startSpot + 1] = colorName;
		boardColors[row][startSpot - 1] = colorName;
	}

	return;
}


//function that will turn the down facing J block to the normal, left facing, J block
void turn4JBlock(char boardColors[][10], char colorName, int &startSpot, int &row)
{
	bool canMove = true;

	//check to see if can turn block, turn it clockwise rotating on left side
	if (boardColors[row - 1][startSpot] != 00 || boardColors[row + 1][startSpot] != 00
		|| boardColors[row + 1][startSpot - 1] != 00)
		canMove = false;

	//if can move is still true, turn the block
	if (canMove == true)
	{
		//rotate on middle up and down block
		boardColors[row][startSpot - 1] = 00;
		boardColors[row][startSpot + 1] = 00;
		boardColors[row + 1][startSpot + 1] = 00;
		boardColors[row - 1][startSpot] = colorName;
		boardColors[row + 1][startSpot] = colorName;
		boardColors[row + 1][startSpot - 1] = colorName;
	}

	return;
}


//function that will more the left facing J block down
void down1JBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	bool canMove = true;

	//check to see if can move down
	if (row + 1 == 19 || boardColors[row + 2][startSpot] != 00 ||
		boardColors[row + 2][startSpot - 1] != 00)
		canMove = false;


	//if cannot move down, set doneMoving to true
	if (canMove == false)
		doneMoving = true;

	//if can move down, then move down 
	if (canMove == true)
	{
		//move down
		boardColors[row - 1][startSpot] = 00;
		boardColors[row + 1][startSpot - 1] = 00;
		boardColors[row + 2][startSpot] = colorName;
		boardColors[row + 2][startSpot - 1] = colorName;
		row = row + 1;

		//check to see if the there's anything below it
		if (row + 1 == 19 || boardColors[row + 2][startSpot] != 00 ||
			boardColors[row + 2][startSpot - 1] != 00)
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


//function that will move the up facing J block down
void down2JBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	bool canMove = true;

	//check to see if can move down
	if (row + 1 == 19 || boardColors[row + 1][startSpot - 1] != 0
		|| boardColors[row + 1][startSpot] != 00 || boardColors[row + 1][startSpot + 1] != 00)
		canMove = false;


	//if cannot move down, set doneMoving to true
	if (canMove == false)
		doneMoving = true;

	//if can move down, then move down 
	if (canMove == true)
	{
		//move down
		boardColors[row - 1][startSpot - 1] = 00;
		boardColors[row][startSpot] = 00;
		boardColors[row][startSpot + 1] = 00;
		boardColors[row + 1][startSpot - 1] = colorName;
		boardColors[row + 1][startSpot] = colorName;
		boardColors[row + 1][startSpot + 1] = colorName;
		row = row + 1;

		//check to see if the there's anything below it
		if (row + 1 == 19 || boardColors[row + 1][startSpot - 1] != 0
			|| boardColors[row + 1][startSpot] != 00 || boardColors[row + 1][startSpot + 1] != 00)
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


//function that will move the right facing J block down
void down3JBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	bool canMove = true;

	//check to see if can move down
	if (row + 1 == 19 || boardColors[row + 2][startSpot] != 0 
		|| boardColors[row][startSpot + 1] != 00)
		canMove = false;


	//if cannot move down, set doneMoving to true
	if (canMove == false)
		doneMoving = true;

	//if can move down, then move down 
	if (canMove == true)
	{
		//move down
		boardColors[row - 1][startSpot] = 00;
		boardColors[row - 1][startSpot + 1] = 00;
		boardColors[row + 2][startSpot] = colorName;
		boardColors[row][startSpot + 1] = colorName;
		row = row + 1;

		//check to see if the there's anything below it
		if (row + 1 == 19 || boardColors[row + 2][startSpot] != 0
			|| boardColors[row][startSpot + 1] != 00)
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


//function that will move the down facing J block down
void down4JBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving)
{
	bool canMove = true;

	//check to see if can move down
	if (row + 1 == 19 || boardColors[row + 2][startSpot + 1] != 00 
		|| boardColors[row + 1][startSpot] != 00 || boardColors[row + 1][startSpot - 1] != 00)
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
		boardColors[row][startSpot + 1] = 00;
		boardColors[row + 1][startSpot - 1] = colorName;
		boardColors[row + 1][startSpot] = colorName;
		boardColors[row + 2][startSpot + 1] = colorName;
		row = row + 1;

		//check to see if the there's anything below it
		if (row + 1 == 19 || boardColors[row + 2][startSpot + 1] != 00
			|| boardColors[row + 1][startSpot] != 00 || boardColors[row + 1][startSpot - 1] != 00)
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
