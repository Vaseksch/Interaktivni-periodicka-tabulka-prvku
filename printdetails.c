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
    printIfvalueIsValid(inputFileStructure.Ar, "relativni atomova hmotnost: %.3f", 5, 4);
    printIfvalueIsValid(inputFileStructure.electronegativity, "elektronegativita: %.3f", 5, 5);
    printIfvalueIsValid(inputFileStructure.boilingPoint, "bod varu: %.3f", 5, 6);
    printf(" %cC", 248);
    printIfvalueIsValid(inputFileStructure.meltingPoint, "bod tani: %.3f", 5, 7);
    printf(" %cC", 248);
    printLine(5, staticLabelPosY + 8, "skupina: %s", inputFileStructure.Group);
    printLine(5, staticLabelPosY + 9, "skupenstvi: %s", inputFileStructure.StandardState);
    printLine(5, staticLabelPosY + 10, "objevitel/misto objeveni: %s", inputFileStructure.discoverer);
    printLine(5, staticLabelPosY + 11, "rok objeveni: %s", inputFileStructure.discoveryYear);

    while (*inptPtr != 2)
    {
        *inptPtr = keyDown();
    }
    system("cls");
    drawBoard(fptr, 0);
    printStaticLabels();
    updateCursorPosition(fptr, *inptPtr);
    updateOutput();
}