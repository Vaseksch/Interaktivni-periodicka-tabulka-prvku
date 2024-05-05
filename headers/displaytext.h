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
#define dataOutputOffset 20

struct modeBasedOutput
{
    char dataLine0[32];
    char dataLine1[32];
    char modeName[32];
};

struct modeBasedOutput modeBasedOutput1;

void clearPreviousOutput(int XOrigin, int YOrigin);

void printLineString(int XOrigin, int YOrigin, char *lineInput);

void printLineFloat(int XOrigin, int YOrigin, float *floatInput);

void printLineNum(int XOrigin, int YOrigin, int *numInput);

void printStaticLabels();

void getMode();

void printIfvalueIsValid(float value, char format[5], int line);

void updateOutput();

#endif