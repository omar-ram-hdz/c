#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
void main(){
    initscr();
    printw("Hola mundo");
    getch();
    endwin();
}