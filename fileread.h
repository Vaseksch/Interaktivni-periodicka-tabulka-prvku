#ifndef FILEREAD_H_   
#define FILEREAD_H_

struct fileInputData{
    char elementntNumber[4];
    char shortcut[3];
    char laName[20];
    char czName[20];
    float Ar;
    float electronegativity;
};

struct fileInputData inputFileStructure;

int readElement(FILE * fptr, int number);

#endif