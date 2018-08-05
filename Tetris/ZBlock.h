#pragma once



void move1ZBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void move2ZBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void turn1ZBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void turn2ZBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void down1ZBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
void down2ZBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
