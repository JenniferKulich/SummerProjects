#pragma once


void move1TBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void move2TBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void move3TBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void move4TBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void turn1TBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void turn2TBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void turn3TBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void turn4TBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void down1TBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
void down2TBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
void down3TBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
void down4TBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);