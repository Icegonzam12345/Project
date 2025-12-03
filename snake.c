#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

#define ROWS 20
#define COLS 20
#define MAX_SNAKE_LENGTH (ROWS * COLS)

char world[ROWS][COLS];

struct Segment{
    int y;
    int x;
};

struct Segment snake[MAX_SNAKE_LENGTH];
int snake_length;

int apple_y = -1;
int apple_x = -1;

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

    for(int i = 0; i < snake_length; i++){
        snake[i].y = start_y;
        snake[i].x = start_x - i; //horizontal snake
    }

    world[snake[0].y][snake[0].x] = 'X'; //draw snake
    for(int i = 1; i < snake_length; i++){
        world[snake[i].y][snake[i].x] = '*'; //body
    }
}

void place_apple(void){
    while(1){
        int y = rand() % (ROWS - 2) + 1; //random position within walls
        int x = rand() % (COLS - 2) + 1;

        if(world[y][x] == ' '){ //only place apple in empty space
            world[y][x] = '@'; //apple character
            apple_y = y;
            apple_x = x;
            break;
        }
    }
}

void redraw_world(void){
    for(int r = 1; r < ROWS - 1; r++){
        for(int c = 1; c < COLS - 1; c++){
            world[r][c] = ' '; //clear game area
        }
    }
    if(apple_y >= 0 && apple_x >= 0){
        world[apple_y][apple_x] = '@'; //redraw apple
    }
    world[snake[0].y][snake[0].x] = 'X'; //redraw head
    for(int i = 1; i < snake_length; i++){
        world[snake[i].y][snake[i].x] = '*'; //redraw body
    }
}



int main(void){
   srand(time(NULL));

   initscr();
   noecho();
   curs_set(0);
   keypad(stdscr, TRUE);
   nodelay(stdscr, TRUE);

   inital_world();
   inital_snake();
   place_apple();

   int dir_y = 0;
   int dir_x = 1;
   int game_over = 0;
  
   while (!game_over){
         int ch = getch();
         switch (ch) {
                case KEY_UP:
                  if(dir_y != 1){ dir_y = -1; dir_x = 0; } //move up
                    break;

                case KEY_DOWN:
                  if(dir_y != -1){ dir_y = 1; dir_x = 0; } //move down
                    break;

                case KEY_LEFT:
                  if(dir_x != 1){ dir_y = 0; dir_x = -1; } //move left
                    break;

                case KEY_RIGHT:
                  if(dir_x != -1){ dir_y = 0; dir_x = 1; } //move right
                    break;

                case 'q':
                case 'Q':
                    game_over = 1; //quit game
                    break;

                default:
                    break;
         }
   int new_y = snake[0].y + dir_y; // new head position
   int new_x = snake[0].x + dir_x; // new head position

   if(world[new_y][new_x] == '#' || world[new_y][new_x] == '*'){
       game_over = 1; //hit wall or self
       continue;
   }
   int ate_apple = (world[new_y][new_x] == '@');

   if(ate_apple){ //remove apple if eaten and not max length
         if(snake_length < MAX_SNAKE_LENGTH){
                snake_length++; //increase length
         }
         apple_y = -1; 
         apple_x = -1;
   }
   for(int i = snake_length - 1; i > 0; i--){
       snake[i] = snake[i - 1]; //move body
   }
   snake[0].y = new_y; //update head 
   snake[0].x = new_x;

   if(ate_apple){
        place_apple(); //place new apple
   }
  
   redraw_world();
   draw_world();
   refresh();
   napms(120); //control speed
   }
    // Game over message
    nodelay(stdscr, FALSE); // make getch() blocking again
    mvprintw(ROWS, 0, "Game Over! Press any key to exit.");
    refresh();
    getch();

    endwin();
    return 0;
}