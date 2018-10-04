/*
** EPITECH PROJECT, 2018
** random_killer
** File description:
** random_killer
*/

#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

void random_killer(void)
{
	pid_t next_pid;
	char *next_process;
	int pid_max = get_pid_max();

	if (pid_max < 1)
		return;
	while (1) {
		next_pid = rand() % pid_max;
		next_process = get_process_name(next_pid);
		if (next_process && *next_process) {
			printf("The next death will be %d and is called %s\n",
			       next_pid, next_process);
			sleep(1);

#ifndef SAFE
			kill(next_pid, SIGKILL);
#endif
		}
		free(next_process);
	}
}
