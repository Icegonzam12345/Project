#include <stdio.h>
#include <ncurses.h>

#define ROWS 20
#define COLS 20
#define MAX_SNAKE_LENGTH (ROWS * COLS)

char world[ROWS][COLS];

struct Segment{
    int y;
    int x;
} 

struct Segment snake[MAX_SNAKE_LENGTH];
int snake_length;


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

void inital_snake(void){
    snake_length = 3; //starting length

    int start_y = ROWS / 2; //snake starting position (middle of board)
    int start_x = COLS / 2;

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
