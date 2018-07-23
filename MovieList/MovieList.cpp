#include <iostream>
#include <fstream>
#include "ListFunctions.h"

using namespace std;


int menu();


int main()
{
	int menuChoice = 0;

	//open the master list file and check if opened
	ofstream output;
	output.open("MasterList.txt");
	if (!output.is_open())
	{
		cout << "Error. Could not open file." << endl;
		exit(1);
	}

	//call the menu
	menuChoice = menu();
	if (menuChoice == 4)
		return 0;

	//do what the menu says based on the menu choice

	//close the file
	output.close();
	return 0;
}


//menu for asking user what they would like to do to master list
int menu()
{
	int userChoice;

	cout << "Pick an option for what you would like to do" << endl;
	cout << "1) Add an item" << endl << "2) Remove an item" << endl;
	cout << "3) Clear the entire list" << endl << "4) Quit" << endl;

	cin >> userChoice;

	while (userChoice < 1 || userChoice > 4)
	{
		cout << "Must pick an option between 1 and 4. Pick again" << endl;
		cin >> userChoice;
	}


	return userChoice;
}