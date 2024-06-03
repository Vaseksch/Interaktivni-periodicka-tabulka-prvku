#ifndef FILEREAD_H_   
#define FILEREAD_H_

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

int readElement(FILE *fptr, int number);

#endif