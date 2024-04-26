#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"headers/fileread.h"

int readElement(FILE * fptr, int number){
    char lineInput[64];
    int line = 1;
    fseek(fptr, 0, SEEK_SET);
    while(fgets(lineInput, sizeof(lineInput)/sizeof(char), fptr)){
        if(line == number){
            char * elementNumber = strtok(lineInput, ";");
            strcpy(inputFileStructure.elementntNumber, elementNumber);
            char * elementShortcut = strtok(NULL, ";");
            strcpy(inputFileStructure.shortcut, elementShortcut);
            char * elementNameLa = strtok(NULL, ";");        
            strcpy(inputFileStructure.laName, elementNameLa);
            char * elementNameCz = strtok(NULL, ";");        
            strcpy(inputFileStructure.czName, elementNameCz);
            char * elementAr = strtok(NULL, ";");       
            inputFileStructure.Ar = atof(elementAr);
            char * elementElectronegativity = strtok(NULL, ";");       
            inputFileStructure.electronegativity = atof(elementElectronegativity);            
            char * elementGroup = strtok(NULL, ";");       
            inputFileStructure.Group = atoi(elementGroup);
            char * elementState = strtok(NULL, ";");       
            inputFileStructure.StandardState = atoi(elementState);
            return 0;
        }else{
            line++;
        }
    }

}

