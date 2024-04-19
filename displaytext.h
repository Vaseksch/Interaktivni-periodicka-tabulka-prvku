#include <stdio.h>
#include "movement.h"
#include <string.h>
#ifndef DISPLAYTEXT_H_   
#define DISPLAYTEXT_H_

void printLineString(int XOrigin, int YOrigin, char * lineInput){
    moveCursor(XOrigin, YOrigin);
    for(int spaceCount = 0; spaceCount < 20; spaceCount++){
        printf(" ");
    }
    moveCursor(XOrigin, YOrigin);
    printf("%s", lineInput);
}

void printLineFloat(int XOrigin, int YOrigin, float * floatInput){
    moveCursor(XOrigin, YOrigin);
    for(int spaceCount = 0; spaceCount < 20; spaceCount++){
        printf(" ");
    }
    moveCursor(XOrigin, YOrigin);
    printf("%.3f", *floatInput);
}

void printLabels(){
    moveCursor(25, 4);
    printf("cislo prvku:");
    moveCursor(25, 5);
    printf("zkratka:");
    moveCursor(25, 6);
    printf("cesky nazev:");
    moveCursor(25, 7);
    printf("latinsky nazev:");
    moveCursor(25, 8);
    printf("Ar:");
    moveCursor(curentPosition.XX, curentPosition.YY);
}

void updateOutput(){
    printLineString(41, 4, inputFileStructure.elementntNumber);
    printLineString(41, 5, inputFileStructure.shortcut);
    printLineString(41, 6, inputFileStructure.czName);
    printLineString(41, 7, inputFileStructure.laName);
    printLineFloat(41, 8, &inputFileStructure.Ar);



}

#endif