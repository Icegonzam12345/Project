#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

char world[ROWS][COLS];

void inital_world(void){
    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            if(r == 0 || r == ROWS - 1 || c == 0 || c == COLS - 1){
                world[r][c] = '#'; //walls
            } else {
                world[r][c] = ' '; //empty space for game area
            }
        }
    }
}
void draw_world(void){
    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            mvaddch(r, c, world[r][c]);
        }
    }
}



int main(void){
   initscr();
   noecho();
   curs_set(0);

   inital_world();
   draw_world();

   refresh();
   getch();

   endwin();
   return 0;
}
