#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"headers/fileread.h"

//function reads line from file, splits the line into tokens and saves those tokens into structure
int readElement(FILE * fptr, int number){
    char lineInput[128];
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
            char * elementState = strtok(NULL, ";");
            strcpy(inputFileStructure.StandardState, elementState);
            char * elementGroup = strtok(NULL, ";");
            strcpy(inputFileStructure.Group, elementGroup);
            char * elementDiscoverer = strtok(NULL, ";");        
            strcpy(inputFileStructure.discoverer, elementDiscoverer);
            char * elementYear = strtok(NULL, ";");        
            strcpy(inputFileStructure.discoveryYear, elementYear);
            char * elementBoil = strtok(NULL, ";");       
            inputFileStructure.boilingPoint = atof(elementBoil);
            char * elementMelt = strtok(NULL, ";");       
            inputFileStructure.meltingPoint = atof(elementMelt);           
            return 0;
        }else{
            line++;
        }
    }
}