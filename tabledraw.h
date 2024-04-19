#include <stdio.h>
#include <stdlib.h>
#include "movement.h"
#include "fileread.h"
#include "tabledata.h"
#ifndef TABLEDRAW_H_   
#define TABLEDRAW_H_


void drawBoard(FILE * fptr){
    for(int col = 0; col < column; col++){
        for(int rowTop = 0; rowTop < row; rowTop++){
            //pro nacteni vlastnosti boxu vymaskuji prvni 3 bity
            switch (grid[col][rowTop] & 0x7)
            {
            case 0:
                printf("     ");
                break;
            case 1:
                printf("+----");
                break;
            case 2:
                printf("+----+");
                break;
            case 3:
                printf("    ");
                break;
            case 4:
                printf("+----");
                break;
            case 5:
                printf("+----+");
                break;
            case 6:
                printf("----");
                break;
            }
        }
        printf("\n");
        for(int rowWall = 0; rowWall < row; rowWall++){
            switch (grid[col][rowWall] & 0x7)  //pro nacteni vlastnosti boxu vymaskuji prvni 3 bity
            {
            case 0:
                printf("     ");
                break;
            case 1:
            readElement(fptr, grid[col][rowWall] >> 3);
                printf("| %s ", inputFileStructure.shortcut);
                break;
            case 2:
            readElement(fptr, grid[col][rowWall] >> 3);
                printf("| %s |", inputFileStructure.shortcut);
                break;
            case 3:
                printf("    ");
                break;
            case 4:
                printf("     ");
                break;
            case 5:
                printf("     ");
                break;
            case 6:
                printf("    ");
                break;
            }
        }
        printf("\n");
        alignCursor();
    }
}

#endif