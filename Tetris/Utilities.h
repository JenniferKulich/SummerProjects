#pragma once



char getColorName();
void everythingTogether(char boardColors[][10]);
void printBoard(char board[][10], char colorName);
void checkIfCompleteRow(char boardColors[][10]);
bool gameOve(char boardColors[][10]);
void allMoveIBlock(char colorName, char boardColors[][10], bool &doesQuit);
void allMoveTBlock(char colorName, char boardColors[][10], bool &doesQuit);
void allMoveLBlock(char colorName, char boardColors[][10], bool &doesQuit);
void allMoveJBlock(char colorName, char boardColors[][10], bool &doesQuit);
void allMoveZBlock(char colorName, char boardColors[][10], bool &doesQuit);
void allMoveSBlock(char colorName, char boardColors[][10], bool &doesQuit);
void allMoveOBlock(char colorName, char boardColors[][10], bool &doesQuit);