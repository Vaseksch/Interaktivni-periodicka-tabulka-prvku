#include <stdio.h>
#include <stdlib.h>
#include "headers/movement.h"
#include "headers/tabledata.h"
#include "headers/tabledraw.h"
#include "headers/displaytext.h"
#include "headers/colors.h"

void setColors(FILE * fptr, int * ptrInpt){
  if(colors == 0 && tableMode == 3 || colors == 1 && tableMode != 3){
            system("cls");
            drawBoard(fptr, 0);
            printStaticLabels();
            updateCursorPosition(fptr ,*ptrInpt);
            if(colors == 0){
              colors = 1;
            }else{
              colors = 0;
            }
        }
}