##
## EPITECH PROJECT, 2017
## matchstick
## File description:
## makefile
##

SRC     =	$(wildcard src/*.c)			\
		$(wildcard src/render_component/*.c)	\
		$(wildcard src/load_component/*.c)	\

OBJ     =       $(SRC:.c=.o)

NAME    =	ENGINE_2D

CFLAGS	=	-Wall -Wextra -Iinclude

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lc_graph_prog -lm

debug:  CFLAGS += -g
debug:	re clean

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re:     fclean all

.PHONY:	all debug clean fclean re
