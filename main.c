#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "getkey.h"
#include "movement.h"
#include "fileread.h"

int getch(void);

int main(){
    FILE * fptr = fopen("data/data.csv", "r");
    int inpt = 0;
    drawBoard(fptr);
    updateCursorPosition(fptr ,inpt);
    printf("\033[?25l");
    while (inpt != -1)
    {
        inpt = keyDown(); 
        updateCursorPosition(fptr ,inpt);
    }
    fclose(fptr);
    return 0;
}
