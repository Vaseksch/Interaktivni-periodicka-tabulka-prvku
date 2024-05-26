#ifndef MOLECULARWEIGHT_H_
#define MOLECULARWEIGHT_H_

float molecularWeight;
char molecule[118];
char moleculeOutput[64];
char holdNumber[10];
char holdElement[10];
int saved;

void buildMoleculeOutput(FILE *fptr);

int saveOutput();

void molecularWeightScreen(FILE * fptr, int * inptPtr);

void addMolecularWeight();

void resetMolecularWeight();

#endif