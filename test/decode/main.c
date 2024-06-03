#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fileInputData{
    char elementntNumber[4];
    char shortcut[3];
    char laName[20];
    char czName[20];
    float Ar;
    float electronegativity;
    char Group[20];
    char StandardState[20];
    char discoveryYear[40];
    char discoverer[40];
    float boilingPoint;
    float meltingPoint;
};

struct fileInputData inputFileStructure;

void decodeProperties(char * propertiesinput){
    int convertedInput = atoi(propertiesinput);

    switch (convertedInput & 3)
    {
    case 1:
        strcpy(inputFileStructure.StandardState, "pevne");
        break;
    case 2:
        strcpy(inputFileStructure.StandardState, "kapalne");
        break;
    case 3:
        strcpy(inputFileStructure.StandardState, "plynne");
        break;        
    }

    switch (convertedInput >> 2)
    {
    case 1:
        strcpy(inputFileStructure.Group, "nekov");
        break;
    case 2:
        strcpy(inputFileStructure.Group, "alkalicky kov");
        break;
    case 3:
        strcpy(inputFileStructure.Group, "kov a. zemin");
        break;
    case 4:
        strcpy(inputFileStructure.Group, "prechodny kov");
        break;
    case 5:
        strcpy(inputFileStructure.Group, "polokov");
        break;
    case 6:
        strcpy(inputFileStructure.Group, "neprechodny kov");
        break;
    case 7:
        strcpy(inputFileStructure.Group, "vzacny plyn");
        break;
    case 8:
        strcpy(inputFileStructure.Group, "lanthanoid");
        break;
    case 9:
        strcpy(inputFileStructure.Group, "aktinoid");
        break;
    case 10:
        strcpy(inputFileStructure.Group, "Halogen");
        break;              
    }
}


int readElement(FILE * fptr, FILE * fptrout){
    char lineInput[128];
    int line = 1;
    fseek(fptr, 0, SEEK_SET);
    while(fgets(lineInput, sizeof(lineInput)/sizeof(char), fptr)){
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
            char * elementProperties = strtok(NULL, ";");
            decodeProperties(elementProperties);
            char * elementDiscoverer = strtok(NULL, ";");        
            strcpy(inputFileStructure.discoverer, elementDiscoverer);
            char * elementYear = strtok(NULL, ";");        
            strcpy(inputFileStructure.discoveryYear, elementYear);
            char * elementBoil = strtok(NULL, ";");       
            inputFileStructure.boilingPoint = atof(elementBoil);
            char * elementMelt = strtok(NULL, ";");       
            inputFileStructure.meltingPoint = atof(elementMelt); 
            fprintf(fptrout, "%s;%s;%s;%s;%.3f;%.3f;%s;%s;%s;%s;%.3f;%.3f\n", inputFileStructure.elementntNumber, inputFileStructure.shortcut, inputFileStructure.laName, inputFileStructure.czName, inputFileStructure.Ar,inputFileStructure.electronegativity,inputFileStructure.StandardState, inputFileStructure.Group, inputFileStructure.discoverer, inputFileStructure.discoveryYear, inputFileStructure.boilingPoint, inputFileStructure.meltingPoint);             
    }

}

int main(){
    FILE * fptrin = fopen("datain.csv", "r");
    FILE * fptrout = fopen("dataout.csv", "w");

    readElement(fptrin, fptrout);
    fclose(fptrin);
    fclose(fptrout);
    return 0;
}