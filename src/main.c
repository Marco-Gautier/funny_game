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

int main(void)
{
	srand(time(NULL));
	random_killer();
	return 0;
}
