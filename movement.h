#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "table.h"
#ifndef MOVEMENT_H_   
#define MOVEMENT_H_

#define upperBound 3
#define lowerBound 20
#define leftBound 7
#define rightBound 47




struct position{
    int XX;
    int YY;
    int line;
    int col;
};

struct position curentPosition;

void alignCursor(){
    curentPosition.XX = 7;
    curentPosition.YY = 3;
    curentPosition.line = 1;
    curentPosition.col = 1;
}

void cursorCordsUpdate(int input){
  //pro nacteni vlastnosti boxu se vzdy vymaskuji prvni 3 bity
  switch (input)
    {
    case 3:
    if((grid[curentPosition.col - 1][curentPosition.line] & 7)== 1 || (grid[curentPosition.col - 1][curentPosition.line] & 7) == 2){
      curentPosition.YY -= 2;
      curentPosition.col--;
    }
      break;
    case 4:
    if((grid[curentPosition.col + 1][curentPosition.line] & 7) == 1 || (grid[curentPosition.col + 1][curentPosition.line] & 7) == 2){
      curentPosition.YY += 2;
      curentPosition.col++;
    }
      break;
    case 5:
    if((grid[curentPosition.col][curentPosition.line - 1] & 7) == 1 || (grid[curentPosition.col][curentPosition.line - 1] & 7) == 2){
      curentPosition.XX -= 5;
      curentPosition.line--;
    }
    break;
    case 6:
    if((grid[curentPosition.col][curentPosition.line + 1] & 7) == 1 || (grid[curentPosition.col][curentPosition.line + 1] & 7) == 2){
      curentPosition.XX += 5;
      curentPosition.line++;
    }
      break;     
  }
}

int moveCursor()
{
    COORD poscur;
    poscur.X = curentPosition.XX;
    poscur.Y = curentPosition.YY;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), poscur);
    return 0;
}

void updateCursorPosition(int input){
  moveCursor();
  printf("\033[0mXX\033[0m");
  cursorCordsUpdate(input);
  moveCursor();
  printf("\033[47;30mXX\033[0m");
}

#endif