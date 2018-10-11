/*
** EPITECH PROJECT, 2018
** get_random_process
** File description:
** get_random_process
*/

#include <fcntl.h>
#include <limits.h>
#include <ncurses.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "game.h"

char *get_process_name(pid_t pid)
{
	int fd;
	char *tmp;
	char buf[PATH_MAX];
	char name[PATH_MAX] = {'\0'};

	if (snprintf(buf, sizeof(buf), "/proc/%d/cmdline", pid) == -1)
		return NULL;
	fd = open(buf, O_RDONLY);
	if (fd == -1)
		return NULL;
	if (read(fd, name, sizeof(name)) == -1)
		return NULL;
	close(fd);
	tmp = strchr(name, ' ');
	if (tmp)
		*tmp = '\0';
	return strdup(name);
}

struct target get_random_process(int pid_max)
{
	struct target process = {
		.pid = -1,
		.name = NULL,
		.pos_y = 0,
		.pos_x = rand() % (COLS ? COLS : 1)
	};

	while (1) {
		process.pid = rand() % pid_max;
		process.name = get_process_name(process.pid);
		if (process.pid != getpid() && process.name && *process.name)
			return process;
	}
}
