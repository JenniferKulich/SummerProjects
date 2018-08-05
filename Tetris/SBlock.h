#pragma once

void move1SBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void move2SBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void turn1SBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void turn2SBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void down1SBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
void down2SBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
