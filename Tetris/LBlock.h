#pragma once



void move1LBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void move2LBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void move3LBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void move4LBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void turn1LBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void turn2LBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void turn3LBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void turn4LBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void down1LBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
void down2LBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
void down3LBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
void down4LBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
