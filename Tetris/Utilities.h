#pragma once



char getColorName();
void everythingTogether(char boardColors[][10]);
void allMoveOBlock(char colorName, char boardColors[][10], bool &doesQuit);
void printBoard(char board[][10]);
void checkIfCompleteRow(char boardColors[][10]);
bool gameOve(char boardColors[][10]);