#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

struct fileInputData{
    char elementntNumber[4];
    char shortcut[3];
    char laName[20];
    char czName[20];
    float Ar;
    float electronegativity;
    int Group;
    int StandardState;
    char code;
};

struct fileInputData inputFileStructure;

int main(){
    FILE * fptrR = fopen("data.csv", "r");
    FILE * fptrW = fopen("dataw.csv", "w");

    char lineInput[64];

    while(fgets(lineInput, sizeof(lineInput)/sizeof(char), fptrR)){
        
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

            inputFileStructure.code = inputFileStructure.StandardState | (inputFileStructure.Group << 2);

            fprintf(fptrW, "%s;%s;%s;%s;%.3f;%.3f;%d\n", inputFileStructure.elementntNumber, inputFileStructure.shortcut, inputFileStructure.laName, inputFileStructure.czName, inputFileStructure.Ar, inputFileStructure.electronegativity, inputFileStructure.code);
    }
    fclose(fptrR);
    fclose(fptrW);
    return 0;
}