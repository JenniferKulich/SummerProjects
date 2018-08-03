#pragma once


void moveHorizontalIBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void moveVerticalIBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void turnHorizontalIBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void turnVerticalIBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void downHorizontalIBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
void downVerticalIBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);