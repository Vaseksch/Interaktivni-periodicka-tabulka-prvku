#include <stdio.h>
#include <stdlib.h>
#include "movement.h"
#ifndef GRID_H_   
#define GRID_H_
#define column 12
#define row 19


int grid[column][row] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2},
    {0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 1, 1, 1, 1, 2},
    {0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 1, 1, 1, 1, 2},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},

};




void drawBoard(){
    for(int col = 0; col < column; col++){
        for(int rowTop = 0; rowTop < row; rowTop++){
            switch (grid[col][rowTop])
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
            }
        }
        printf("\n");
        for(int rowWall = 0; rowWall < row; rowWall++){
            switch (grid[col][rowWall])
            {
            case 0:
                printf("     ");
                break;
            case 1:
                printf("| XX ");
                break;
            case 2:
                printf("| XX |");
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
            }
        }
        printf("\n");
        alignCursor();
    }
}

#endif 