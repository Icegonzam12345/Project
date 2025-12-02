#include <stdio.h>
#include <ncurses.h>

#define rows 20;
#define cols 20;

char world[rows][cols];

void initalworld(void){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
             if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1){
                world[r][c] = '#';
            } else {
                world[r][c] = ' ';
        }
    }
}









int main(int argv, char **argc) {

}
