#include <stdio.h>
#include <stdlib.h>
#ifndef GETKEY_H_
#define GETKEY_H_

int getch(void);

int keyDown()
{
    int output = 0;
    int inpt = 0;
    inpt = getch();
switch (inpt) {
    case 13: //enter
      output = 1;
      break;
    case 8: //backspace
      output = 2;
      break;
    case 72: //up
      output = 3;
      break;
    case 80: //down
      output = 4;
      break;
    case 75: //left
      output = 5;
      break;
    case 77: //right
      output = 6;
      break;
    case 27: //esc
    puts("\a");
      if(MessageBoxW(GetConsoleWindow(),L"opravdu chcete program ukončit",L"konec",MB_YESNO | MB_ICONQUESTION | MB_APPLMODAL) == 6){
        output = -1;
      }else{
        output = 0;
      }
      break;      
  }
  return output;
}

#endif