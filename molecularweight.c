#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <Windows.h>
#include "headers/fileread.h"
#include "headers/molecularweight.h"
#include "headers/displaytext.h"
#include "headers/tabledraw.h"
#include "headers/getkey.h"

void buildMoleculeOutput(FILE *fptr){
    for(int arrayPosition = 0; arrayPosition < 118; arrayPosition++){
        moleculeOutput[arrayPosition] = 0;
    }
    for(int pos = 0; pos < 118; pos++){
        if(molecule[pos] != 0){
            readElement(fptr, pos);
            for(int index = 0; inputFileStructure.shortcut[index] != 0; index++){
                if(inputFileStructure.shortcut[index] != ' '){
                    holdElement[index] = inputFileStructure.shortcut[index];
                }
            }
            strcat(moleculeOutput, holdElement);
            if(molecule[pos] > 1){
                 sprintf(holdNumber, "%d", molecule[pos]);
                 strcat(moleculeOutput, holdNumber);
            }
        }
    }
}

int saveOutput(){
    FILE * fptrOutput = fopen("output/vysledky.txt", "a+");
    if(fptrOutput == NULL){
        MessageBoxW(GetConsoleWindow(),L"Soubor se nepodařilo otevřít",L"ERROR",MB_OK | MB_ICONERROR | MB_APPLMODAL | MB_DEFBUTTON2);
        return 0;
    }
    MessageBoxW(GetConsoleWindow(),L"výsledek uložen do vysledky.txt",L"uložení",MB_OK | MB_ICONINFORMATION | MB_APPLMODAL | MB_DEFBUTTON1);
    fprintf(fptrOutput, "Molekula: %s       Mm: %.3f g/mol\n", moleculeOutput, molecularWeight);
    fclose(fptrOutput);
    saved = 1;
}

void molecularWeightScreen(FILE *fptr, int *inptPtr)
{
    system("cls");
    buildMoleculeOutput(fptr);

    //prints molecule data
    clearPreviousOutput(15, 8);
    clearPreviousOutput(30, 8);
    printLine(5, staticLabelPosY + 5, "Molekula: %s", moleculeOutput);
    printLine(5, staticLabelPosY + 6, "Mm: %.3f g/mol", molecularWeight);

    //controls
    printLine(5, staticLabelPosY + 21, "ulozit: INSERT");
    printLine(5, staticLabelPosY + 22, "vynulovat: DELETE");
    printLine(5, staticLabelPosY + 23, "navrat: BACKSPACE");
    printLine(5, staticLabelPosY + 24, "konec: ESC");

    

    // waits for backspace to end the loop
    while (*inptPtr != 2)
    {
        *inptPtr = keyDown();
        if (*inptPtr == 7)
        {
            saveOutput();   
        }
        if (*inptPtr == 9)
        {
            if(saved == 0){
               puts("\a");
            if(MessageBoxW(GetConsoleWindow(),L"Chcete před vynulovaní výsledek uložit?",L"vynulování",MB_YESNO | MB_ICONQUESTION | MB_APPLMODAL | MB_DEFBUTTON1) == 6){
                saveOutput();
            } 
            }
            buildMoleculeOutput(fptr);
            resetMolecularWeight();
            clearPreviousOutput(15, 8);
            clearPreviousOutput(30, 8);
            printLine(5, staticLabelPosY + 5, "Molekula: %s", moleculeOutput);
            printLine(5, staticLabelPosY + 6, "Mm: %.3f g/mol", molecularWeight);
        }
        if (*inptPtr == -1)
        {
            if(saved == 0){
               puts("\a");
            if(MessageBoxW(GetConsoleWindow(),L"Chcete před vynulovaní výsledek uložit?",L"vynulování",MB_YESNO | MB_ICONQUESTION | MB_APPLMODAL | MB_DEFBUTTON1) == 6){
                saveOutput();
            } 
            }
            exit(0);
        }
    }
    // clears console and redraws the table
    system("cls");
    drawBoard(fptr, 0);
    printStaticLabels();
    updateCursorPosition(fptr, *inptPtr);
    updateOutput();
}

void addMolecularWeight()
{
    saved = 0;
    molecularWeight += inputFileStructure.Ar;
    molecule[atoi(inputFileStructure.elementntNumber)]++;
}

void resetMolecularWeight()
{
    molecularWeight = 0;
    saved = 0;
    for(int arrayPosition = 0; arrayPosition < 118; arrayPosition++){
        molecule[arrayPosition] = 0;
        moleculeOutput[arrayPosition] = 0;
    }
}

