#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "tabledata.h"
#include "fileread.h"
#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#define upperBound 3
#define lowerBound 20
#define leftBound 7
#define rightBound 47

struct position
{
  int XX;
  int YY;
  int line;
  int col;
};

struct position curentPosition;

void alignCursor()
{
  curentPosition.XX = 6;
  curentPosition.YY = 3;
  curentPosition.line = 1;
  curentPosition.col = 1;
}

void cursorCordsUpdate(int input)
{
  int foundNearest = 0;
  // pro nacteni vlastnosti boxu se vzdy vymaskuji prvni 3 bity
  switch (input)
  {
  case 3:
  //loop oedcita vzdalenost do konce pole
    for (int distance = 1; distance < curentPosition.col && foundNearest == 0; distance++)
    {
      //hledani nejblizsi obsaditelne bunky
      if ((grid[curentPosition.col - distance][curentPosition.line] & 7) == 1 || (grid[curentPosition.col - distance][curentPosition.line] & 7) == 2)
      {
        curentPosition.YY -= 2 * distance;
        curentPosition.col -= distance;
        foundNearest = 1;
      }
    }
    break;
  case 4:
    for (int distance = 1; distance < (column - curentPosition.col) && foundNearest == 0; distance++)
    {
      if ((grid[curentPosition.col + distance][curentPosition.line] & 7) == 1 || (grid[curentPosition.col + distance][curentPosition.line] & 7) == 2)
      {
        curentPosition.YY += 2 * distance;
        curentPosition.col += distance;
        foundNearest = 1;
      }
    }
    break;
  case 5:
    for (int distance = 1; distance < curentPosition.line && foundNearest == 0; distance++)
    {
      if ((grid[curentPosition.col][curentPosition.line - distance] & 7) == 1 || (grid[curentPosition.col][curentPosition.line - distance] & 7) == 2)
      {
        curentPosition.XX -= 5 * distance;
        curentPosition.line -= distance;
        foundNearest = 1;
      }
    }
    break;
  case 6:
    for (int distance = 1; distance < (row - curentPosition.line) && foundNearest == 0; distance++)
    {
      if ((grid[curentPosition.col][curentPosition.line + distance] & 7) == 1 || (grid[curentPosition.col][curentPosition.line + distance] & 7) == 2)
      {
        curentPosition.XX += 5 * distance;
        curentPosition.line += distance;
        foundNearest = 1;
      }
    }
    break;
  }
}

int moveCursor(int XX, int YY)
{
  COORD poscur;
  poscur.X = XX;
  poscur.Y = YY;

  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), poscur);
  return 0;
}

void updateCursorPosition(FILE *fprt, int input)
{
  moveCursor(curentPosition.XX, curentPosition.YY);
  printf("\033[0m %s \033[0m", inputFileStructure.shortcut);
  cursorCordsUpdate(input);
  int search = grid[curentPosition.col][curentPosition.line] >> 3;
  moveCursor(curentPosition.XX, curentPosition.YY);
  readElement(fprt, search);
  printf("\033[47;30m %s \033[0m", inputFileStructure.shortcut);
}

void printData()
{
  moveCursor(19, 2);
  clearLine();
  moveCursor(19, 2);
  printf("Znacka: %s", inputFileStructure.shortcut);
  moveCursor(19, 3);
  clearLine();
  moveCursor(19, 3);
  printf("Cesky nazev: %s", inputFileStructure.czName);
  moveCursor(19, 4);
  clearLine();
  moveCursor(19, 4);
  printf("Latinsky nazev: %s", inputFileStructure.laName);
  moveCursor(curentPosition.XX, curentPosition.YY);
}

#endif