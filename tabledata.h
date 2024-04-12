#include <stdio.h>
#include <stdlib.h>
#ifndef TABLEDATA_H_   
#define TABLEDATA_H_
#define column 12
#define row 19

// v kazdem slotu jsou ulozeny 2 parametry: 1) vlastnost boxu prvni 3 bity. 2) cislo prvku nasledujicich 7 bitu = cislo prvku.
int grid[column][row] = {
    {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x12},
    {0x0, 0x19, 0x22, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x29, 0x31, 0x39, 0x41, 0x49, 0x52},
    {0x0, 0x59, 0x62, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x69, 0x71, 0x79, 0x81, 0x89, 0x92},
    {0x0, 0x99, 0xa1, 0xa9, 0xb1, 0xb9, 0xc1, 0xc9, 0xd1, 0xd9, 0xe1, 0xe9, 0xf1, 0xf9, 0x101, 0x109, 0x111, 0x119, 0x122},
    {0x0, 0x129, 0x131, 0x139, 0x141, 0x149, 0x151, 0x159, 0x161, 0x169, 0x171, 0x179, 0x181, 0x189, 0x191, 0x199, 0x1a1, 0x1a9, 0x1b2},
    {0x0, 0x1b9, 0x1c2, 0x6, 0x241, 0x249, 0x251, 0x259, 0x261, 0x269, 0x271, 0x279, 0x281, 0x289, 0x291, 0x299, 0x2a1, 0x2a9, 0x2b2},
    {0x0, 0x2b9, 0x2c2, 0x3, 0x341, 0x349, 0x351, 0x359, 0x361, 0x369, 0x371, 0x379, 0x381, 0x389, 0x391, 0x399, 0x3a1, 0x3a9, 0x3b2},
    {0x0, 0x4, 0x5, 0x3, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x5},
    {0x0, 0x0, 0x0, 0x0, 0x1c9, 0x1d1, 0x1d9, 0x1e1, 0x1e9, 0x1f1, 0x1f9, 0x201, 0x209, 0x211, 0x219, 0x221, 0x229, 0x231, 0x23a},
    {0x0, 0x0, 0x0, 0x0, 0x2c9, 0x2d1, 0x2d9, 0x2e1, 0x2e9, 0x2f1, 0x2f9, 0x301, 0x309, 0x311, 0x319, 0x321, 0x329, 0x331, 0x33a},
    {0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x5},

};

#endif