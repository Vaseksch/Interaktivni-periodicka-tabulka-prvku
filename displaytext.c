#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "headers/fileread.h"
#include "headers/movement.h"
#include "headers/displaytext.h"
#include "headers/tabledata.h"

//function clears previous output
void clearPreviousOutput(int XOrigin, int YOrigin)
{
    moveCursor(XOrigin, YOrigin);
    for (int spaceCount = 0; spaceCount < maxOutputLenght; spaceCount++){
        printf(" ");
    }
    moveCursor(XOrigin, YOrigin);
}

//universal function to print data in required position
void printLine(int XOrigin, int YOrigin, char *format, ...)
{
    clearPreviousOutput(XOrigin, YOrigin);
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

void printStaticLabels()
{
    // column and line numbers
    for (int columnNumbers = 1; columnNumbers <= 18; columnNumbers++){
        if (columnNumbers == 1 || columnNumbers == 18){
            moveCursor(7 + (5 * columnNumbers), 3);
        }
        if (columnNumbers == 2 || (columnNumbers > 12 && columnNumbers < 18)){
            moveCursor(7 + (5 * columnNumbers), 5);
        }
        if (columnNumbers > 2 && columnNumbers < 13){
            moveCursor(7 + (5 * columnNumbers), 9);
        }
        printf("%d", columnNumbers);
    }
    for (int columnNumbers = 1; columnNumbers <= 7; columnNumbers++){
        moveCursor(8, 3 + columnNumbers * 2);
        printf("%d", columnNumbers);
        if (columnNumbers == 7){
            int temp = 0;
            for (columnNumbers = 9; columnNumbers <= 10; columnNumbers++){
                moveCursor(23, 3 + columnNumbers * 2);
                printf("%d", 6 + temp);
                temp++;
            }
        }
    }

    // labels for basic element informations
    printLine(staticLabelPosX, staticLabelPosY, "%s", "cislo prvku:");
    printLine(staticLabelPosX, staticLabelPosY + 1, "%s", "zkratka:");
    // controls labels
    printLine(4, 24, "%s", "pohyb: < > ^ v");
    printLine(4, 25, "%s", "podrobnosti: ENTER");
    printLine(4, 26, "%s", "dalsi rezim: PG_DN");
    printLine(4, 27, "%s", "predchozi rezim: PG_UP");
    printLine(40, 26, "%s", "vypocet Mm: HOME");
    printLine(40, 27, "%s", "pridat do vypoctu Mm: INSERT");
    printLine(80, 26, "%s", "rezim:");
    printLine(80, 28, "%s", "Aktualni ke dni 4.5.2022 podle IUPAC");
    printLine(4, 28, "%s", "konec: ESC");
    // reset cursor to previous position
    moveCursor(curentPosition.XX, curentPosition.YY);
}

//checks if value of element isnt 0, if it is 0 then it prints N/A, int line argument is Y offset from data output anchor position
void printIfvalueIsValid(float value, char format[5], int position_X , int position_Y){
    if(value != 0){
          printLine(position_X, staticLabelPosY + position_Y, format, value);  
        }else{
          printLine(position_X, staticLabelPosY + position_Y, "%s", "N/A");
        }
}

// function prints data of selected element, int added to staticLabelPosY is Y offset from data output anchor position
void updateOutput()
{
    printLine(staticLabelPosX + dataOutputOffset, staticLabelPosY + 0, "%s", inputFileStructure.elementntNumber);
    printLine(staticLabelPosX + dataOutputOffset, staticLabelPosY + 1, "%s", inputFileStructure.shortcut);
    switch (tableMode)
    {
    case 1:
        printLine(staticLabelPosX + dataOutputOffset, staticLabelPosY + 2, "%s", inputFileStructure.czName);
        printLine(staticLabelPosX + dataOutputOffset, staticLabelPosY + 3, "%s", inputFileStructure.laName);
        printLine(staticLabelPosX, staticLabelPosY + 2, "cesky nazev:");
        printLine(staticLabelPosX, staticLabelPosY + 3, "latinsky nazev:   ");
        printLine(staticLabelPosX + 52, staticLabelPosY + 23, "1 - nazvy");
        break;
    case 2:
        printIfvalueIsValid(inputFileStructure.Ar, "%.3f", staticLabelPosX + dataOutputOffset, 2);
        printIfvalueIsValid(inputFileStructure.electronegativity, "%.3f", staticLabelPosX + dataOutputOffset, 3);
        printLine(staticLabelPosX, staticLabelPosY + 2, "Ar:         ");
        printLine(staticLabelPosX, staticLabelPosY + 3, "elektronegativita:");
        printLine(staticLabelPosX + 52, staticLabelPosY + 23, "2 - hodnoty");
        break;
    case 3:
        printLine(staticLabelPosX + dataOutputOffset, staticLabelPosY + 2, "%s", inputFileStructure.Group);
        printLine(staticLabelPosX + dataOutputOffset, staticLabelPosY + 3, "%s", inputFileStructure.StandardState);
        printLine(staticLabelPosX, staticLabelPosY + 2, "skupina:    ");
        printLine(staticLabelPosX, staticLabelPosY + 3, "skupenstvi:       ");
        printLine(staticLabelPosX + 52, staticLabelPosY + 23, "3 - vlastnosti");
        break;
    case 4:
        printIfvalueIsValid(inputFileStructure.boilingPoint, "%.3f", staticLabelPosX + dataOutputOffset, 2);
        printIfvalueIsValid(inputFileStructure.meltingPoint, "%.3f", staticLabelPosX + dataOutputOffset, 3);
        printLine(staticLabelPosX, staticLabelPosY + 2, "bod varu C:    ");
         printLine(staticLabelPosX, staticLabelPosY + 3, "bod tani C:       ");
        printLine(staticLabelPosX + 52, staticLabelPosY + 23, "4 - teploty");
        break;  
    case 5:
        printLine(staticLabelPosX + dataOutputOffset, staticLabelPosY + 2, "%s", inputFileStructure.discoveryYear);
        printLine(staticLabelPosX + dataOutputOffset, staticLabelPosY + 3, "%s", inputFileStructure.discoverer);
        printLine(staticLabelPosX, staticLabelPosY + 2, "rok objevanei:    ");
        printLine(staticLabelPosX, staticLabelPosY + 3, "objevitel:       ");
        printLine(staticLabelPosX + 52, staticLabelPosY + 23, "5 - historie");
        break;                
    }
}