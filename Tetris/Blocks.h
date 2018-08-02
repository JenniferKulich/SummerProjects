#pragma once

#include <time.h>
#include <stdlib.h>
//where the functions are declared


/*
TYPES OF BLOCKS

I block
J block
L block
O block
S block
T block
Z block

*/

void startIBlock(char boardColors[][10], int color, int &startSpot);
void startJBlock(char boardColors[][10], int color, int &startSpot);
void startLBlock(char boardColors[][10], int color, int &startSpot);
void startOBlock(char boardColors[][10], int color, int &startSpot);
void startSBlock(char boardColors[][10], int color, int &startSpot);
void startTBlock(char boardColors[][10], int color, int &startSpot);
void startZBlock(char boardColors[][10], int color, int &startSpot);

char getColorName(int color);

