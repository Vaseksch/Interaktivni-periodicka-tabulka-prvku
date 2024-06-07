#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "headers/tabledata.h"
#include "headers/fileread.h"
#include "headers/movement.h"

void alignCursor()
{
  curentPosition.XX = 11;
  curentPosition.YY = 5;
  curentPosition.line = 2;
  curentPosition.col = 2;
}

void cursorCordsUpdate(int input)
{
  int foundNearest = 0;
  //box properties are stored in first 3 bits
  switch (input)
  {
  case 3:
    for (int distance = 1; distance < curentPosition.col && foundNearest == 0; distance++)
    {
      //looks for next avalible box
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
  if(tableMode == 3){
    printf("\x1b[38;5;%sm %s \x1b[0;37m", inputFileStructure.color,  inputFileStructure.shortcut);
  }else{
    printf("\x1b[0m %s \033[0m", inputFileStructure.shortcut);
  }
  
  cursorCordsUpdate(input);

  //number of selected element is saved to int search
  int search = grid[curentPosition.col][curentPosition.line] >> 3;

  moveCursor(curentPosition.XX, curentPosition.YY);
  readElement(fprt, search);
  if(tableMode == 3){
    printf("\x1b[48;5;%sm %s \x1b[0;37m", inputFileStructure.color,  inputFileStructure.shortcut);
  }else{
    printf("\x1b[47;30m %s \033[0m", inputFileStructure.shortcut);
  }
}