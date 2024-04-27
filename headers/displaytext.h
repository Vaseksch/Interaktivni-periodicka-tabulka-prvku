#include <stdio.h>
#include "fileread.h"
#include "movement.h"
#include <wchar.h>
#include <string.h>
#ifndef DISPLAYTEXT_H_
#define DISPLAYTEXT_H_
#define maxOutputLenght 15
#define staticLabelPosX 35
#define staticLabelPosY 3
#define dataOutputOffset 16

void clearPreviousOutput(int XOrigin, int YOrigin)
{
    moveCursor(XOrigin, YOrigin);
    for (int spaceCount = 0; spaceCount < maxOutputLenght; spaceCount++)
    {
        printf(" ");
    }
    moveCursor(XOrigin, YOrigin);
}

void printLineString(int XOrigin, int YOrigin, char *lineInput)
{
    clearPreviousOutput(XOrigin, YOrigin);
    printf("%s", lineInput);
}

void printLineFloat(int XOrigin, int YOrigin, float *floatInput)
{
    clearPreviousOutput(XOrigin, YOrigin);
    printf("%.3f", *floatInput);
}

void printLineNum(int XOrigin, int YOrigin, int *numInput)
{
    clearPreviousOutput(XOrigin, YOrigin);
    printf("%d", *numInput);
}

void printMode(int XOrigin, int YOrigin)
{
    moveCursor(XOrigin, YOrigin);
    switch (tableMode)
    {
    case 1:
        printf("1 - zakladni  ");
        break;

    case 2:
        printf("2 - skupenstvi");
        break;
    case 3:
        printf("3 - skupiny   ");
        break;
    }
}

void printStaticLabels()
{
    // column and line numbers
    for (int columnNumbers = 1; columnNumbers <= 18; columnNumbers++)
    {
        if (columnNumbers == 1 || columnNumbers == 18)
        {
            moveCursor(7 + (5 * columnNumbers), 3);
        }
        if (columnNumbers == 2 || (columnNumbers > 12 && columnNumbers < 18))
        {
            moveCursor(7 + (5 * columnNumbers), 5);
        }
        if (columnNumbers > 2 && columnNumbers < 13)
        {
            moveCursor(7 + (5 * columnNumbers), 9);
        }
        printf("%d", columnNumbers);
    }
    for (int columnNumbers = 1; columnNumbers <= 7; columnNumbers++)
    {
        moveCursor(8, 3 + columnNumbers * 2);
        printf("%d", columnNumbers);
        if (columnNumbers == 7)
        {
            int temp = 0;
            for (columnNumbers = 9; columnNumbers <= 10; columnNumbers++)
            {
                moveCursor(23, 3 + columnNumbers * 2);
                printf("%d", 6 + temp);
                temp++;
            }
        }
    }

    // labels for dataOutput
    moveCursor(staticLabelPosX, staticLabelPosY);
    printf("cislo prvku:");
    moveCursor(staticLabelPosX, staticLabelPosY + 1);
    printf("zkratka:");
    moveCursor(staticLabelPosX, staticLabelPosY + 2);
    printf("cesky nazev:");
    moveCursor(staticLabelPosX, staticLabelPosY + 3);
    printf("latinsky nazev:");
    moveCursor(staticLabelPosX, staticLabelPosY + 4);
    printf("Ar:");
    // controls labels
    moveCursor(5, 25);
    printf("pohyb: < > ^ v");
    moveCursor(5, 26);
    printf("dalsi rezim: PG_DN");
    moveCursor(5, 27);
    printf("predchozi rezim: PG_UP");
    moveCursor(80, 26);
    printf("rezim:");
    moveCursor(5, 28);
    printf("konec: ESC");
    // reset cursor to previous position
    moveCursor(curentPosition.XX, curentPosition.YY);
}

//function prints data of selected element
void updateOutput()
{
    printLineString(staticLabelPosX + dataOutputOffset, staticLabelPosY + 0, inputFileStructure.elementntNumber);
    printLineString(staticLabelPosX + dataOutputOffset, staticLabelPosY + 1, inputFileStructure.shortcut);
    printLineString(staticLabelPosX + dataOutputOffset, staticLabelPosY + 2, inputFileStructure.czName);
    printLineString(staticLabelPosX + dataOutputOffset, staticLabelPosY + 3, inputFileStructure.laName);
    printLineFloat(staticLabelPosX + dataOutputOffset, staticLabelPosY + 4, &inputFileStructure.Ar);
    // printLineNum(staticLabelPosX + dataOutputOffset, staticLabelPosY + 5, &tableMode);
    printMode(87, 26);
}

#endif