//START OF ARRAY IS THE FINISH LINE
#include <iostream>

using namespace std;

int rollOrQuit();
void setUpBoard(char board[]);
void printBoard(char board[]);

int main()
{
	char board[40];
	int numPlayers = 0;
	char playerOne = 'a';
	char playerTwo = 'b';
	int answerContinue = 0;


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
	board[3] = '5';
	board[17] = '5';
	board[12] = '6';
	board[30] = '6';
	board[26] = '7';
	board[35] = '7';

	return;
}

void printBoard(char board[])
{
	int i = 0;
	
	for (i = 0; i < 40; i++)
	{
		if (i % 8 == 0)
			cout << endl;
		cout << board[i] << " ";
	}
	return;
}