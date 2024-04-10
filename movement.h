#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#ifndef MOVEMENT_H_   
#define MOVEMENT_H_

struct position{
    int XX;
    int YY;
};

struct position curentPosition;

void alignCursor(){
    curentPosition.XX = 7;
    curentPosition.YY = 3;
}

void cursorCordsUpdate(int input){
  switch (input)
    {
    case 3:
      curentPosition.YY -= 2;
      break;
    case 4:
      curentPosition.YY += 2;
      break;
    case 5:
      curentPosition.XX -= 5;
      break;
    case 6:
      curentPosition.XX += 5;
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