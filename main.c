#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "tabledraw.h"
#include "getkey.h"
#include "movement.h"
#include "fileread.h"
#include "displaytext.h"

int getch(void);

int main(){
    SetConsoleTitle("Periodicka tabulka prvku");
    FILE * fptr = fopen("data/data.csv", "r");
    int inpt = 0;
    drawBoard(fptr);
    printLabels();
    updateCursorPosition(fptr ,inpt);
    printf("\033[?25l");
    while (inpt != -1)
    {
        updateOutput();
        inpt = keyDown(); 
        updateCursorPosition(fptr ,inpt); 
    }
    fclose(fptr);
    return 0;
}
