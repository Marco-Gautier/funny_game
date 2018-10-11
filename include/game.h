/*
** EPITECH PROJECT, 2018
** lul
** File description:
** lul
*/

#ifndef GAME_H_
#define GAME_H_

#pragma once

struct target {
	pid_t	pid;
	char	*name;
	int	pos_y;
	int	pos_x;
};

struct target get_random_process(int pid_max);

#endif /* GAME_H_ */
