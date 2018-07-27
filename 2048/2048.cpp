#include <iostream>

using namespace std;

void printBoard(int board[][4]);

int main()
{
	int board[4][4];
	int i, n;

	//set the whole board to zero
	for (i = 0; i < 4; i++)
	{
		for (n = 0; n < 4; n++)
			board[i][n] = 0;
	}

	//initialize the board

	board[3][3] = 2;
	board[3][2] = 2;


	printBoard(board);




	return 0;
}

void printBoard(int board[][4])
{
	int i, n;

	for (i = 0; i < 4; i++)
	{
		for (n = 0; n < 4; n++)
		{
			cout << board[i][n] << " ";
		}
		
		cout << endl;
	}
}