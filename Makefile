##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

SRC     =	$(wildcard src/*.c)		\

OBJ     =       $(SRC:.c=.o)

NAME    =	ENGINE_2D

CFLAGS	=	-Wall -Wextra -Iinclude

CSFML	=	-lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system

MATH 	=	-lm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CSFML) $(MATH)

debug:  CFLAGS += -g
debug:	re clean

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

cleanvg:
	rm -f vgcore*

re:     fclean all

.PHONY:	all debug clean fclean re