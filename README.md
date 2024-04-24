
Interactive Periodic Table of Elements
Description:

This program is designed for educational purposes, particularly in the fields of chemistry and, to a lesser extent, molecular physics. The implementation of a molecular weight calculation function is also under consideration, but its inclusion will depend on the final project scope.

Features:

Navigate the periodic table using arrow keys or WASD keys.
Switch between different table modes using R or F1 - F3 keys
Technical Details:

The project is organized into header files for modularity.
The periodic table is rendered in one of the header files using ASCII characters (+ and -).
The table displays the element symbol.
Hovering over a box highlights it and displays basic information about the element (symbol, atomic number, Czech name, English name, relative atomic mass, electronegativity, etc.).
Element information is loaded from a CSV file into a custom structure.
A separate header file handles file loading.
Each line in the CSV file contains information about a single element.
Information is read as a string and parsed into tokens using the strtok function.
Tokens are then stored in the aforementioned structure.
Additional header files contain functions for handling keyboard input and table navigation.
Element data is stored in a two-dimensional array.
The first 3 bits in the array define the rendering behavior of a box.
The remaining 7 bits store the element's atomic number, used for retrieving information from the structure.

Notes:

The implementation of the molecular weight calculation function is currently under consideration.
