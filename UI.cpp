#include "UI.h"

char borderChar = (char)219;
void initUI() {
     initscr();
     nodelay(stdscr,TRUE);
     noecho();
     curs_set(0);
}

void printBorder() {
     
     for(int i = 0; i < COLS; i++) { // For the top and bottom
          move(0,i); // Starts at the top and print from i to COLS
          addch(borderChar);

          move(LINES - 1, i); // Starts at the bottom (LINES - 1) and i and goes on till COLS - 1
          addch(borderChar);
     }

     for(int i = 1; i < LINES - 1; i++) { // For the left and right
          move(i,0); // Starts at i,0 (1,0) till (LINES - 1, 0) 
          addch(borderChar);

          move(i,COLS-1); // Starts at (1,COLS-1) till (LINES - 1, COLS - 1)
          addch(borderChar);
     }
}

void destroyUI() {
     endwin();
}