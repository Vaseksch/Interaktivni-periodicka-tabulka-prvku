#ifndef MOLECULARWEIGHT_H_
#define MOLECULARWEIGHT_H_

float molecularWeight;
char moleculeOutput[64];
char shortcutRemovedSpaces[3];
char atomCount[4];
int saved;
int withoutSpacesCount;

struct atom {
    char shortcut[3]; 
    int number; 
    int count;
    int full;
};

struct atom elementList[16];
  

void buildMoleculeOutput(FILE *fptr);

int saveOutput();

void molecularWeightScreen(FILE * fptr, int * inptPtr);

int addMolecularWeight();

void resetMolecularWeight();

#endif