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

#include <unistd.h>
#include <stdbool.h>

void init_curses(void)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	nodelay(stdscr, TRUE);
}

int get_x(int typed, int x)
{
	if (typed == KEY_LEFT) {
		x--;
	} else if (typed == KEY_RIGHT) {
		x++;
	}
	return x;
}

void hand_clear()
{
	move(LINES - 1, 0);
	for (int i = 0; i < COLS; i++)
		printw(" ");
}

void game()
{
	char *container = "\\______/";
	int typed;
	int x = 0;

	while (1) {
		typed = getch();
		if (typed == 'q')
			return;
		x = get_x(typed, x);
		hand_clear();
		move(LINES - 1, x);
		printw("%s", container);
		refresh();
	}
}

int main(void)
{
	init_curses();
	game();
	endwin();
	return 0;
}
