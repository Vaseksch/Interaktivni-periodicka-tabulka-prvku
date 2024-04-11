#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef FILEREAD_H_   
#define FILEREAD_H_

struct fileInputData{
    char shortcut[2];
    char laName[20];
    char czName[20];
    float Ar;
    float electronegativity;
};

struct fileInputData inputFileStructure;

int readElement(FILE * fptr, int number){
    char lineInput[64];
    int line = 1;
    fseek(fptr, 0, SEEK_SET);
    while(fgets(lineInput, sizeof(lineInput)/sizeof(char), fptr)){
        if(line == number){
            char * part1 = strtok(lineInput, ";");
            char * part2 = strtok(NULL, ";");
            strcpy(inputFileStructure.shortcut, part2);
            return 0;
        }else{
            line++;
        }
    }

}

char * tableFill(FILE * fptr){
    char lineInput[64];
    fgets(lineInput, sizeof(lineInput)/sizeof(char), fptr);
                char * part1 = strtok(lineInput, ";");
                char * part2 = strtok(NULL, ";");
                strcpy(inputFileStructure.shortcut, part2);
}
#endif
