#pragma once

class MenuOptions
{
public:
	void addItem(node *&headptr,  string Name);
	void removeItem();
	void clearList();

private:
	node *headptr;

};

struct node
{
	string movieName;
	struct node *next;
};