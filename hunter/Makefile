##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for project my_hunter
##

SRC	=	./sources/set_functions.c\
		./sources/set_menu.c\
		./sources/hunter_functions.c\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter


all:	compile clean

compile:	$(OBJ)
	gcc $(OBJ) -o $(NAME) -g -Wall -Wextra -l csfml-audio -l csfml-graphics -l csfml-system -l csfml-window -L./ -lmy

re:	fclean compile clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
