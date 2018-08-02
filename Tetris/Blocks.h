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

void startIBlock(char boardColors[][10], int color);
void startJBlock(char boardColors[][10], int color);
void startLBlock(char boardColors[][10], int color);
void startOBlock(char boardColors[][10], int color);
void startSBlock(char boardColors[][10], int color);
void startTBlock(char boardColors[][10], int color);
void startZBlock(char boardColors[][10], int color);

char getColorName(int color);
