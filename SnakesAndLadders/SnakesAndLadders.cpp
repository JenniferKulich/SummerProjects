#include <iostream>

using namespace std;

int main()
{
	int board[5][8] = { 0 };
	int numPlayers = 0;


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



	return 0;
}