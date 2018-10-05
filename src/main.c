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

#include <sys/types.h>
#include <sys/wait.h>

#include <signal.h>
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

void clear_last_line()
{
	move(LINES - 1, 0);
	for (int i = 0; i < COLS; i++)
		printw(" ");
}

void print_container(char *container, int x)
{
	clear_last_line();
	move(LINES - 1, x);
	printw("%s", container);
	refresh();
}

void clear_main(void)
{
	move(0, 0);
	for (int i = 0; i < LINES - 2; i++)
		for (int j = 0; j < COLS; j++)
			printw(" ");
}

void game()
{
	char *container = "\\_____/";
	int typed;
	int x = 0;
	static int clock = -1;
	int i = 0;

	while (1) {
		if (clock != time(NULL)) {
			clear_main();
			clock = time(NULL);
			move(i++, 1);
			printw("a");
		}
		typed = getch();
		if (typed == 'q')
			return;
		x = get_x(typed, x);
		print_container(container, x);	
	}
}

int main(void)
{
	init_curses();
	game();
	endwin();
	return 0;
}
