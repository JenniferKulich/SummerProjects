#include <iostream>
#include <fstream>

using namespace std;

int main()
{

	//open the master list file and check if opened
	ofstream output;
	output.open("MasterList.txt");
	if (!output.is_open())
	{
		cout << "Error. Could not open file." << endl;
		exit(1);
	}



	//close the file
	output.close();
	return 0;
}