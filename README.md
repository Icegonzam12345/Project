Snake game by Isaac Gonzalez

Gameplay:

Game board is a 20x20 grid
Walls ( # ) surround the edges of the board
The snake's head is X and its body is *
The apple is represented as @
Each time the snake eats an apple, it grows by 1 segment


The game ends if the snake:
- Hits a wall
- Self collison
- The player presses Q to quit

Controls:

Up arrow key -> moves up
Down arrow key -> moves down
Left arrow key -> moves left
Right arrow key -> moves right
Q key -> quit game

Implementation details:
Game area drawn using curse library

initscr() to initialize the game screen
keypad(stdscr, TRUE) to enable arrow keys
nodelay(stdscr, TRUE) for nonblocking input
napms(120) to control the snake’s speed

noechoe() -> makes it so the user inputs aren't drawn onto the game area (from curse library)
srand(time(NULL)) -> spawns apples at random location



How to compile:

gcc snake.c -o output.out -lncurses

Run the game:

./output.out