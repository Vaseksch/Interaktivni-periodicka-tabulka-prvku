#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef FILEREAD_H_   
#define FILEREAD_H_

struct fileInputData{
    char shortcut[3];
    char laName[20];
    char czName[20];
    float Ar;
    float electronegativity;
};

struct fileInputData inputFileStructure;

void clearLine(){
  for(int size = 0; size < 40; size++){
    printf(" ");
  }
  
}

int readElement(FILE * fptr, int number){
    char lineInput[64];
    int line = 1;
    fseek(fptr, 0, SEEK_SET);
    while(fgets(lineInput, sizeof(lineInput)/sizeof(char), fptr)){
        if(line == number){
            char * elementNumber = strtok(lineInput, ";");
            char * elementShortcut = strtok(NULL, ";");
            strcpy(inputFileStructure.shortcut, elementShortcut);
            char * elementNameLa = strtok(NULL, ";");        
            strcpy(inputFileStructure.laName, elementNameLa);
            char * elementNameCz = strtok(NULL, ";");        
            strcpy(inputFileStructure.czName, elementNameCz);
            return 0;
        }else{
            line++;
        }
    }

}


#endif
