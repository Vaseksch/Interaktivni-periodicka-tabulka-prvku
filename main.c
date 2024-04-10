#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "getkey.h"
#include "movement.h"

int getch(void);

int main(){
    int inpt = 0;
    drawBoard();
    updateCursorPosition(inpt);
    printf("\033[?25l");
    while (inpt != -1)
    {
        inpt = keyDown(); 
        updateCursorPosition(inpt);
    }

}
