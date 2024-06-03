#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <Windows.h>
#include "headers/fileread.h"
#include "headers/molecularweight.h"
#include "headers/displaytext.h"
#include "headers/tabledraw.h"
#include "headers/getkey.h"

//builds shortcut of molecule
void buildMoleculeOutput(FILE *fptr){
    moleculeOutput[0] = 0;
    for(int arrayPosition = 0; arrayPosition < 16; arrayPosition++){
        if (elementList[arrayPosition].full == 1)
        {
            //removes spaces
            withoutSpacesCount = 0;
            for(int charecterPosition = 0; charecterPosition < 3; charecterPosition++){
                if(elementList[arrayPosition].shortcut[charecterPosition] != ' '){
                    shortcutRemovedSpaces[withoutSpacesCount] = elementList[arrayPosition].shortcut[charecterPosition];
                    withoutSpacesCount++;
                }
            }
            //appends element shortcut to moleculeOutput
            strcat(moleculeOutput, shortcutRemovedSpaces);
            if (elementList[arrayPosition].count > 1)
            {
                //convetrs int to string and appends count to moleculeOutput
                sprintf(atomCount, "%d", elementList[arrayPosition].count);
                strcat(moleculeOutput, atomCount);
            }    
        } 
    }
}

int saveOutput(){
    FILE * fptrOutput = fopen("output/vysledky.txt", "a+");
    //error handling
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

    clearPreviousOutput(15, 8);
    clearPreviousOutput(30, 8);
    clearPreviousOutput(15, 9);
    clearPreviousOutput(30, 9);
    
    //prints molecule data
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
            if(molecularWeight > 0){
                saveOutput();
            }else{
                MessageBoxW(GetConsoleWindow(),L"Příliž málo prvků v molekule",L"ERROR - nelze uložit",MB_OK | MB_ICONERROR | MB_APPLMODAL | MB_DEFBUTTON2);
            }     
        }
        if (*inptPtr == 9)
        {
            if(saved == 0 && molecularWeight > 0){
               puts("\a");
            if(MessageBoxW(GetConsoleWindow(),L"Chcete před vynulovaní výsledek uložit?",L"vynulování",MB_YESNO | MB_ICONQUESTION | MB_APPLMODAL | MB_DEFBUTTON1) == 6){
                saveOutput();
            } 
            }
            buildMoleculeOutput(fptr);
            resetMolecularWeight();
            clearPreviousOutput(15, 8);
            clearPreviousOutput(30, 8);
            clearPreviousOutput(15, 9);
            clearPreviousOutput(30, 9);
            printLine(5, staticLabelPosY + 5, "Molekula: %s", moleculeOutput);
            printLine(5, staticLabelPosY + 6, "Mm: %.3f g/mol", molecularWeight);
        }
        if (*inptPtr == -1)
        {
            //saves output only if you havent saved it before
            if(saved == 0 && molecularWeight > 0){
               puts("\a");
            if(MessageBoxW(GetConsoleWindow(),L"Chcete před ukončením výsledek uložit?",L"vynulování",MB_YESNO | MB_ICONQUESTION | MB_APPLMODAL | MB_DEFBUTTON1) == 6){
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

int addMolecularWeight()
{
    saved = 0;
    molecularWeight += inputFileStructure.Ar;
    for(int arrayPosition = 0; arrayPosition < 16; arrayPosition++){  
        if(elementList[arrayPosition].full == 1 && strcmp(elementList[arrayPosition].shortcut, inputFileStructure.shortcut) == 0){
            //in case the selected element is already contained in the structure array  
            elementList[arrayPosition].count++;
            return 0;
        }else if (elementList[arrayPosition].full == 0)
        {
            //in case the selected element is not contained in the structure array  
            strcpy(elementList[arrayPosition].shortcut, inputFileStructure.shortcut);
            elementList[arrayPosition].count++;
            elementList[arrayPosition].full = 1;
            return 0;
        }
    }
}

void resetMolecularWeight()
{
    molecularWeight = 0;
    saved = 0;
    moleculeOutput[0] = 0;
    for(int arrayPosition = 0; arrayPosition < 16; arrayPosition++){
        elementList[arrayPosition].shortcut[0] = 0;
        elementList[arrayPosition].count = 0;
        elementList[arrayPosition].full = 0;
    }
}