//START OF ARRAY IS THE FINISH LINE
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int rollOrQuit();
void setUpBoard(char board[]);
void printBoard(char board[]);
void findPlayer(char board[], int &playerSpot, char playerName);
void rollDice(int &diceRoll);
int canPlayerMove(char board[], int playerSpot, int diceRoll);
int moveForChuteOrLadder(char board[], int playerSpot, int diceRoll);
void playerMove(char board[], int playerSpot, char playerName, int diceRoll, int moveType);
bool didWin(int playerSpot);

int main()
{
	char board[41];
	int numPlayers = 0;
	char playerOne = 97 /*a*/;
	char playerTwo = 98 /*b*/;
	char playerThree = 99 /*c*/;
	char playerFour = 100 /*d*/;
	int answerContinue = 0;
	int spotPlayerOne = 0;
	int spotPlayerTwo = 0;
	int spotPlayerThree = 0;
	int spotPlayerFour = 0;


	//initialize the board as all blanks
	for (int i = 0; i < 40; i++)
		board[i] = '_';

	setUpBoard(board);
	printBoard(board);
	cout << endl;


	//ask user how many players they want
	cout << "How many players do you want? ";
	cin >> numPlayers;
	cout << endl;

	//if number of players is less than two or greater than four,
	//ask them again until they answer

	while (numPlayers < 2 || numPlayers > 4)
	{
		cout << "Num of players must be between 2 and 4. Please enter number" <<
			" of players again. ";
		cin >> numPlayers;
		cout << endl;
	}

	
	//ask the user if they would like to roll or quit
	answerContinue = rollOrQuit();
	//if neither roll or quit were selected, ask again until it is
	while (answerContinue == 5)
	{
		cout << "Invalid choice. Please enter R for roll or Q for quit" << endl;
		answerContinue = rollOrQuit();
	}
	//if quit was picked, quit the program
	if (answerContinue == 4)
		return 0;

	int playerOn = 1;
	int diceRoll = 0;
	int typeMove = 0;
	int moveType = 0;
	char playerName;
	//this is to get all of the players started
	while (playerOn <= numPlayers)
	{
		//check which player it's on
		if (playerOn == 1)
			playerName = playerOne;
		if (playerOn == 2)
			playerName = playerTwo;
		if (playerOn == 3)
			playerName = playerThree;
		if (playerOn == 4)
			playerName = playerFour;

		//roll the dice
		rollDice(diceRoll);


		cout << playerName << " " << diceRoll << endl;

		//see what move can be made
		typeMove = canPlayerMove(board, 40, diceRoll);

		//make a move based on what can be done
		if (typeMove == 1)
		{
			//can move to open space
			playerMove(board, 40, playerName, diceRoll, 9);
		}
		if (typeMove == 2)
		{
			//there is a chute or ladder
			moveType = moveForChuteOrLadder(board, 40, diceRoll);
			playerMove(board, 40, playerName, diceRoll, moveType);
		}
		if (typeMove == 3)
		{
			cout << "Player " << playerName << " cannot move :( " <<
				endl << "Turn will be skipped" << endl;
		}

		printBoard(board);
		cout << endl;

		//ask the user if they would like to roll or quit
		answerContinue = rollOrQuit();
		//if neither roll or quit were selected, ask again until it is
		while (answerContinue == 5)
		{
			cout << "Invalid choice. Please enter R for roll or Q for quit" << endl;
			answerContinue = rollOrQuit();
		}
		//if quit was picked, quit the program
		if (answerContinue == 4)
			return 0;

		playerOn++;
	}


	int playerSpot = 0;
	playerName = playerOne;
	playerOn = 1;
	do
	{
		playerSpot = 0;
		//check which player's turn it is
		if (playerOn == 1)
			playerName = playerOne;
		if (playerOn == 2)
			playerName = playerTwo;
		if (playerOn == 3)
			playerName = playerThree;
		if (playerOn == 4)
			playerName = playerFour;

		//find the player on the board
		findPlayer(board, playerSpot, playerName);

		//roll the dice
		rollDice(diceRoll);


		cout << playerName << " " << diceRoll << endl;


		//see if the player can move
		typeMove = canPlayerMove(board, playerSpot, diceRoll);

		//make a move based on what can be done
		if (typeMove == 1)
		{
			//can move to open space
			playerMove(board, playerSpot, playerName, diceRoll, 9);
		}
		if (typeMove == 2)
		{
			//there is a chute or ladder
			moveType = moveForChuteOrLadder(board, playerSpot, diceRoll);
			playerMove(board, playerSpot, playerName, diceRoll, moveType);
		}
		if (typeMove == 3)
		{
			cout << "Player " << playerName << " cannot move :( " <<
				endl << "Turn will be skipped" << endl;
		}

		printBoard(board);
		cout << endl;

		bool playerWon;
		//check if the player did win
		playerWon = didWin(playerSpot);
		if (playerWon == true)
		{
			cout << "Player " << playerOn << " won!";
			return 0;
		}


		//ask the user if they would like to roll or quit
		answerContinue = rollOrQuit();
		//if neither roll or quit were selected, ask again until it is
		while (answerContinue == 5)
		{
			cout << "Invalid choice. Please enter R for roll or Q for quit" << endl;
			answerContinue = rollOrQuit();
		}
		//if quit was picked, quit the program
		if (answerContinue == 4)
			return 0;


		//update the player. If the playerOne is equal to the num of players,
		//restart the player number at one
		if (playerOn == numPlayers)
			playerOn = 1;
		else
			playerOn++;

		
	} while (didWin(playerSpot) == false);
	


	return 0;
}


//function that will ask user if they want to roll or quit
int rollOrQuit()
{
	char choice;
	cout << "Would you like to roll(R) or quit(Q)? ";
	cin >> choice;
	if (choice == 'R' || choice == 'r')
		return 3;
	else if (choice == 'Q' || choice == 'q')
		return 4;
	else
		return 5;
}


//function that will set up board with chutes and ladders
void setUpBoard(char board[])
{
	//add the ladders
	board[4] = '1';
	board[11] = '1';
	board[27] = '2';
	board[6] = '2';
	board[36] = '3';
	board[19] = '3';
	
	//add the chutes
	board[2] = '5';
	board[17] = '5';
	board[13] = '6';
	board[30] = '6';
	board[25] = '7';
	board[34] = '7';

	return;
}


//function that will print the board to the screen in a layout
void printBoard(char board[])
{
	int i = 0;
	
	cout << "FINISH --> " << board[0] << " " << board[1] << " "
		<< board[2] << " " << board[3] << " " << board[4] << " "
		<< board[5] << " " << board[6] << " " << board[7];
	for (i = 8; i < 40; i++)
	{
		if (i % 8 == 0)
		{
			cout << endl;
			cout << "           ";
		}	
		cout << board[i] << " ";
	}
	cout << "<-- START" << endl;
	return;
}


//function that will find the player on the board and return spot
//the spot will start at zero
void findPlayer(char board[], int &playerSpot, char playerName)
{
	int i = 0;

	//look through array to find where player is
	for (i = 0; i < 40; i++)
	{
		if (board[i] == playerName)
			playerSpot = i;
	}
	if(playerSpot == 0)
		playerSpot = 40;
}


//function that will roll the dice
void rollDice(int &diceRoll)
{
	srand(time(NULL));

	//get random number between 1 and 6
	diceRoll = rand() % 6 + 1;
}


//function that will check if player can move
int canPlayerMove(char board[], int playerSpot, int diceRoll)
{
	//check if the spot is open or occupied by another player
	if (board[playerSpot - diceRoll] == 95 /*_*/)
		return 1;
	//check if the spot is a chute or ladder
	if (board[playerSpot - diceRoll] == 49 /*1*/ ||
		board[playerSpot - diceRoll] == 50 /*2*/ ||
		board[playerSpot - diceRoll] == 51 /*3*/ ||
		board[playerSpot - diceRoll] == 53 /*5*/ ||
		board[playerSpot - diceRoll] == 54 /*6*/ ||
		board[playerSpot - diceRoll] == 55 /*7*/ )
		return 2;
	else
		return 3;
}


//function that will act on if there is a chute or ladder
int moveForChuteOrLadder(char board[], int playerSpot, int diceRoll)
{
	//can move will return ladder number
	//can't move will return 10

	//if 1, 2, 3 then it's a ladder
	//check if landing on lower part of ladder
	if(board[playerSpot - diceRoll] == 49 /*1*/)
	{
		if (playerSpot - diceRoll == 11)
			return 1;
		else
			return 10;
	}
		

	if (board[playerSpot - diceRoll] == 50 /*2*/)
	{
		if (playerSpot - diceRoll == 27)
			return 2;
		else
			return 10;
	}

	if (board[playerSpot - diceRoll] == 51 /*3*/)
	{
		if(playerSpot - diceRoll == 36)
			return 3;
		else
			return 10;
	}


	//if 5, 6, 7 then it's a chute
	if (board[playerSpot - diceRoll] == 53 /*5*/)
	{
		if (playerSpot - diceRoll == 3)
			return 5;
		else
			return 10;
	}

	if (board[playerSpot - diceRoll] == 54 /*6*/)
	{
		if (playerSpot - diceRoll == 12)
			return 6;
		else
			return 10;
	}

	if (board[playerSpot - diceRoll] == 55 /*7*/)
	{
		if (playerSpot - diceRoll == 26)
			return 7;
		else
			return 10;
	}

	return 0;
}


//function that will move the player
void playerMove(char board[], int playerSpot, char playerName, int diceRoll, int moveType)
{
	//for ladder number one
	if (moveType == 1)
	{
		board[playerSpot] = 95 /*_*/;
		board[5] = playerName;
	}


	//for ladder number two
	if (moveType == 2)
	{
		board[playerSpot] = 95 /*_*/;
		board[7] = playerName;
	}


	//for ladder number three
	if (moveType == 3)
	{
		board[playerSpot] = 95 /*_*/;
		board[20] = playerName;
	}


	//for chute number 5
	if (moveType == 5)
	{
		board[playerSpot] = 95 /*_*/;
		board[18] = playerName;
	}


	//for chute number 6
	if (moveType == 6)
	{
		board[playerSpot] = 95 /*_*/;
		board[31] = playerName;
	}


	//for chute number 7
	if (moveType == 7)
	{
		board[playerSpot] = 95 /*_*/;
		board[36] = playerName;
	}


	/*for normal move
	just move the player to where they need to go and replace
	where they were with an underscore */
	if (moveType == 9)
	{
		board[playerSpot] = 95 /*_*/;
		board[playerSpot - diceRoll] = playerName;
	}

	if (moveType == 10)
	{
		cout << "Player " << playerName << " cannot move :( " <<
			endl << "Turn will be skipped" << endl;
	}
	
	return;
}


//function that will check to see if player has won
bool didWin(int playerSpot)
{
	if (playerSpot == 1)
		return true;
	else
		return false;

}