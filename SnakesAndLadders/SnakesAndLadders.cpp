#include <iostream>

using namespace std;

int rollOrQuit();

int main()
{
	int board[5][8] = { 0 };
	int numPlayers = 0;
	int answerContinue = 0;


	//ask user for number of players
	cout << "How many players are there? ";
	cin >> numPlayers;
	cout << endl;

	//if number of players less than 2 or greater than 4, have user
	//enter number of players until correct
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
