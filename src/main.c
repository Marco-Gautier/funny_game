/*
** EPITECH PROJECT, 2018
** lul
** File description:
** lul
*/

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

void init_curses(void)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
}

int main(void)
{
	init_curses();
	srand(time(NULL));
	//random_killer();
	endwin();
	return 0;
}
