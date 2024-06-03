#include <stdio.h>
#include <stdlib.h>
#include "headers/fileread.h"
#include "headers/tabledata.h"
#include "headers/movement.h"

//fill int resetPosition with 1 to reset cursor position
//fill int resetPosition with 0 to keep previous cursor position
void drawBoard(FILE *fptr, int resetPosition)
{
    for (int col = 0; col < column; col++)
    {
        for (int rowTop = 0; rowTop < row; rowTop++)
        {
             //first 3 bits are masked
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
        for (int rowWall = 0; rowWall < row; rowWall++)
        {
            //first 3 bits are masked
            switch (grid[col][rowWall] & 0x7)
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
        if(resetPosition == 1){
           alignCursor(); 
        }
    }
}