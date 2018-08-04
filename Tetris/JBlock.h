#pragma once


void move1JBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void move2JBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void move3JBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void move4JBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void turn1JBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void turn2JBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void turn3JBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void turn4JBlock(char boardColors[][10], char colorName, int &startSpot, int &row);
void down1JBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
void down2JBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
void down3JBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
void down4JBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
