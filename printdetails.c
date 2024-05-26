#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <Windows.h>
#include "headers/fileread.h"
#include "headers/printdetails.h"
#include "headers/displaytext.h"
#include "headers/tabledraw.h"
#include "headers/getkey.h"

void printDetails(FILE *fptr, int *inptPtr)
{
    system("cls");

    // this section prints evrey parameter of selected element using function from displaytext.h
    printLine(5, staticLabelPosY + 0, "zkratka prvku: %s", inputFileStructure.shortcut);
    printLine(5, staticLabelPosY + 1, "cislo prvku: %s", inputFileStructure.elementntNumber);
    printLine(5, staticLabelPosY + 2, "cesky nazev: %s", inputFileStructure.czName);
    printLine(5, staticLabelPosY + 3, "latinsky nazev: %s", inputFileStructure.laName);
    
    printLine(5, staticLabelPosY + 4, "relativni atomova hmotnost:");
    printIfvalueIsValid(inputFileStructure.Ar, "%.3f", 33, 4);

    printLine(5, staticLabelPosY + 5, "elektronegativita:");
    printIfvalueIsValid(inputFileStructure.electronegativity, "%.3f", 24, 5);

    printLine(5, staticLabelPosY + 6, "bod varu:");
    printIfvalueIsValid(inputFileStructure.boilingPoint, "%.3f", 15, 6);
    printf(" %cC", 248);

    printLine(5, staticLabelPosY + 7, "bod tani:");
    printIfvalueIsValid(inputFileStructure.meltingPoint, "%.3f", 15, 7);
    printf(" %cC", 248);

    printLine(5, staticLabelPosY + 8, "skupina: %s", inputFileStructure.Group);
    printLine(5, staticLabelPosY + 9, "skupenstvi: %s", inputFileStructure.StandardState);
    printLine(5, staticLabelPosY + 10, "objevitel/misto objeveni: %s", inputFileStructure.discoverer);
    printLine(5, staticLabelPosY + 11, "rok objeveni: %s", inputFileStructure.discoveryYear);
    printLine(5, staticLabelPosY + 23, "navrat: BACKSPACE");
    printLine(5, staticLabelPosY + 24, "konec: ESC");

    //waits for backspace to end the loop
    while (*inptPtr != 2)
    {
        *inptPtr = keyDown();
        if (*inptPtr == -1)
        {
            exit(0);
        }
    }
    //clears console and redraws the table
    system("cls");
    drawBoard(fptr, 0);
    printStaticLabels();
    updateCursorPosition(fptr, *inptPtr);
    updateOutput();
}