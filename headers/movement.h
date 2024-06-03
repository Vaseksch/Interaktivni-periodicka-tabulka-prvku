#ifndef MOVEMENT_H_
#define MOVEMENT_H_

struct position
{
  int XX;
  int YY;
  int line;
  int col;
};

struct position curentPosition;
void alignCursor();
void cursorCordsUpdate(int input);
int moveCursor(int XX, int YY);
void updateCursorPosition(FILE *fprt, int input);

#endif