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
#define dataOutputOffset 19

void clearPreviousOutput(int XOrigin, int YOrigin);
void printLine(int XOrigin, int YOrigin, char *format, ...);
void printStaticLabels();
void printIfvalueIsValid(float value, char format[5], int position_X , int position_Y);
void updateOutput();

#endif