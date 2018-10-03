##
## EPITECH PROJECT, 2018
## lul
## File description:
## lul
##

INC_DIR		=	include/

SRC_DIR		=	src/

SRC			=	$(SRC_DIR)main.c

OBJ			=	$(SRC:.c=.o)

CFLAGS		+= -W -Wall -Wextra \
			-I $(INC_DIR)

LDFLAGS		+= -lncurses

NAME		=	funny_game

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			@rm -f $(OBJ)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
