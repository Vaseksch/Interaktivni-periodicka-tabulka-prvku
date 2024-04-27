#include <stdio.h>
#include <string.h>
#include "headers/fileread.h"
#include "headers/movement.h"
#include "headers/displaytext.h"
#include "headers/tabledata.h"


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

    // labels for basic element informations
    moveCursor(staticLabelPosX, staticLabelPosY);
    printf("cislo prvku:");
    moveCursor(staticLabelPosX, staticLabelPosY + 1);
    printf("zkratka:");
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

void getMode()
{
    switch (tableMode)
    {
    case 1:
        strcpy(modeBasedOutput1.dataLine0, "cesky nazev:");
        strcpy(modeBasedOutput1.dataLine1, "latinsky nazev:   ");
        strcpy(modeBasedOutput1.modeName, "1 - nazvy");
        break;

    case 2:
        strcpy(modeBasedOutput1.dataLine0, "Ar:         ");
        strcpy(modeBasedOutput1.dataLine1, "elektronegativita:");
        strcpy(modeBasedOutput1.modeName, "2 - hodnoty");
        break;
    case 3:

        strcpy(modeBasedOutput1.dataLine0, "skupiny:    ");
        strcpy(modeBasedOutput1.dataLine1, "skupenstvi:       ");
        strcpy(modeBasedOutput1.modeName, "3 - vlastnosti");
        break;
    }
}

// function prints data of selected element
void updateOutput()
{
    getMode();
    printLineString(staticLabelPosX + dataOutputOffset, staticLabelPosY + 0, inputFileStructure.elementntNumber);
    printLineString(staticLabelPosX + dataOutputOffset, staticLabelPosY + 1, inputFileStructure.shortcut);
    switch (tableMode)
    {
    case 1:
        printLineString(staticLabelPosX, staticLabelPosY + 2, modeBasedOutput1.dataLine0);
        printLineString(staticLabelPosX, staticLabelPosY + 3, modeBasedOutput1.dataLine1);
        printLineString(staticLabelPosX + dataOutputOffset, staticLabelPosY + 2, inputFileStructure.czName);
        printLineString(staticLabelPosX + dataOutputOffset, staticLabelPosY + 3, inputFileStructure.laName);
        printLineString(staticLabelPosX + 52, staticLabelPosY + 23, modeBasedOutput1.modeName);
        break;
    case 2:
        printLineString(staticLabelPosX, staticLabelPosY + 2, modeBasedOutput1.dataLine0);
        printLineString(staticLabelPosX, staticLabelPosY + 3, modeBasedOutput1.dataLine1);
        printLineFloat(staticLabelPosX + dataOutputOffset, staticLabelPosY + 2, &inputFileStructure.Ar);
        printLineFloat(staticLabelPosX + dataOutputOffset, staticLabelPosY + 3, &inputFileStructure.electronegativity);
        printLineString(staticLabelPosX + 52, staticLabelPosY + 23, modeBasedOutput1.modeName);
        break;
    case 3:
        printLineString(staticLabelPosX, staticLabelPosY + 2, modeBasedOutput1.dataLine0);
        printLineString(staticLabelPosX, staticLabelPosY + 3, modeBasedOutput1.dataLine1);
        printLineNum(staticLabelPosX + dataOutputOffset, staticLabelPosY + 2, &inputFileStructure.Group);
        printLineNum(staticLabelPosX + dataOutputOffset, staticLabelPosY + 3, &inputFileStructure.StandardState);
        printLineString(staticLabelPosX + 52, staticLabelPosY + 23, modeBasedOutput1.modeName);
        break;
    }
}