#pragma once

class MenuOptions
{
public:
	void addItem();
	void removeItem();
	void clearList();

private:
	node *headptr;

};

struct node
{
	int moveList;
	struct node *next;
};