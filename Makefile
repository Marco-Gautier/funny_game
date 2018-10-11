##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC		=	gcc

SRC_DIR		=	src/

INC_DIR		=	include/

SRC		=	$(SRC_DIR)main.c	\
			$(SRC_DIR)get_random_process.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-W -Wall -Wextra	\
			-I $(INC_DIR)		\
			-O3			\
			-g			\

LDFLAGS		+=	-lncurses		\
			-lpthread

NAME		=	funkill

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o  $(NAME) $(OBJ) $(LDFLAGS)

safe:		CFLAGS += -D SAFE
safe:		re

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
