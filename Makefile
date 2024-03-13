##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/header.c \
		include/my_strlen.c \
		include/my_strcat.c \
		src/sokoban.c \
		src/game.c \
		src/event.c

OBJ	=	$(SRC:.c=.o)

FLAGS	=	-lncurses -Werror -Wall -Wextra

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)
