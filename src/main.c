/*
** EPITECH PROJECT, 2018
** lul
** File description:
** lul
*/

#include <fcntl.h>
#include <ncurses.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include "game.h"

void init_curses(void)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
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

void *drop_pid(void *vargps)
{
	static int clock = -1;
	int i = 0;

	(void)vargps;
	while (1) {
		if (clock != time(NULL)) {
			clear_main();
			clock = time(NULL);
			move(i++, 1);
			printw("a");
		}
	}
	return NULL;
}

void game()
{
	char *container = "\\_____/";
	int typed;
	int x = 0;
	pthread_t tid;

	pthread_create(&tid, NULL, drop_pid, NULL);
	while (1) {
		typed = getch();
		if (typed == 'q')
			return;
		x = get_x(typed, x);
		print_container(container, x);
	}
	pthread_join(tid, NULL);
}

int get_pid_max(void)
{
	char buff[16];
	int fd = open("/proc/sys/kernel/pid_max", O_RDONLY);

	if (fd == -1)
		return 0;
	if (read(fd, buff, sizeof(buff)) == -1)
		return 0;
	return atoi(buff);
}

int main(void)
{
	int pid_max = get_pid_max();
	struct target process = get_random_process(pid_max);

	printf("pid: %d\n", process.pid);
	printf("name: %s\n", process.name);
	printf("pos_y: %d\n", process.pos_y);
	printf("pos_x: %d\n", process.pos_x);

	init_curses();
	game();
	endwin();
	return 0;
}
