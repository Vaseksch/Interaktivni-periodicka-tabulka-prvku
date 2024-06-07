#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "headers/movement.h"
#include "headers/tabledata.h"
#include "headers/printdetails.h"
#include "headers/molecularweight.h"
#include "headers/tabledraw.h"
#include "headers/getkey.h"
#include "headers/displaytext.h"
#include "headers/colors.h"

int getch(void);

int main(){
    SetConsoleTitle("Periodicka tabulka prvku");
    FILE * fptr = fopen("data/data.csv", "r");
    //file check
    if(fptr == NULL){
        MessageBoxW(GetConsoleWindow(),L"Soubor data.csv se nepodařilo otevřít",L"ERROR",MB_OK | MB_ICONERROR | MB_APPLMODAL | MB_DEFBUTTON1);
        return 0;
    }
    int inpt = 0;
    resetMolecularWeight();
    drawBoard(fptr, 1);
    printStaticLabels();
    updateCursorPosition(fptr ,inpt);
    //hide cursor
    printf("\033[?25l");
    
    //while repeats until ESC key isn't hit
    while (inpt != -1)
    {
        updateOutput();
        //waits for input
        inpt = keyDown(); 
        updateCursorPosition(fptr ,inpt);
        //details screen
        if(inpt == 1){
            printDetails(fptr, &inpt);
        }
        //Mm calculation screen
        if(inpt == 8){
            molecularWeightScreen(fptr, &inpt);
        }
        //element is added to molecule 
        if(inpt == 7){
            addMolecularWeight();
        }
        setColors(fptr, &inpt);
    }
    //close file
    fclose(fptr);
    return 0;
}
