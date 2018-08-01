#include <iostream>

using namespace std;

void printBoard(char board[][10]);

int main()
{

	char board[20][10];

	/*int i, n;

	for (i = 0; i < 20; i++)
	{
		for (n = 0; n < 10 ; n++)
		{
			board[i][n] = 66;
		}
	}*/
	

	printBoard(board);


	return 0;
}


//function that will print the board to the screen
void printBoard(char board[][10])
{
	int i, n;
	char vl = (char)186; //vertical double line
	char hl = (char)205; //horizontal double line
	char ulc = (char)201; //upper left corner
	char urc = (char)187; //upper right corner
	char llc = (char)200; //lower left corner
	char lrc = (char)188; //lower right corner

	//top line
	cout << ulc << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl <<
		hl << hl << hl << hl << hl << hl << hl << hl << hl << urc << endl;

	//loop through and print the board
	for (i = 0; i < 20; i++)
	{
		cout << vl;
		for (n = 0; n < 10; n++)
		{
			if (n == 9)
				cout << board[i][n];
			else
				cout << board[i][n] << " ";
		}
		
		cout << vl << endl;
	}

	//bottom row
	cout << llc << hl << hl << hl << hl << hl << hl << hl << hl << hl << hl <<
		hl << hl << hl << hl << hl << hl << hl << hl << hl << lrc << endl;

	return;
}