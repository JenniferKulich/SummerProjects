#pragma once

void moveOBlock(char boardColors[][10], char colorName, int &startSpot, int userMove, int row);
void downOBlock(char boardColors[][10], char colorName, int &startSpot, int &row, bool &doneMoving);
