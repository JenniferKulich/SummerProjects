#include "ListFunctions.h"
#include <string>

using namespace std;

void MenuOptions::addItem(node *&headptr, string Name)
{
	node *temp = new (nothrow)node;
	temp->movieName = Name;
	temp->next = nullptr;

	//check if the list is empty
	//if list empty, add to beginning of list
	if (headptr == nullptr)
	{
		headptr = temp;
	}

	node *prev = nullptr;
	node *curr = nullptr;


	prev = headptr;
	curr = headptr;
	//else, traverse through the list and add to the end of the list
	while (curr != nullptr)
	{
		prev = curr;
		curr = curr->next;
	}

	//once at the end, add the movie
	

	return;
}