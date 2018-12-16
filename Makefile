##
## EPITECH PROJECT, 2018
## Engine
## File description:
## Makefile
##

NAME		=	OmegaEngine

CC			=	gcc

INCLUDE		=	-Iinclude

CSFML		=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

MATH		=	-lm

CFLAGS  	=	-Wall -Wextra -std=c11 $(INCLUDE) $(CSFML) $(MATH)

ENGINE_SRC	=	./src/engine/utility/vector/vector_find_item.c				\
				./src/engine/utility/vector/vector_set.c					\
				./src/engine/utility/vector/vector_access.c					\
				./src/engine/utility/vector/vector_iterate.c				\
				./src/engine/utility/vector/vector_mutation_a.c				\
				./src/engine/utility/vector/vector_construct.c				\
				./src/engine/utility/vector/vector_destruct.c				\
				./src/engine/utility/vector/internal_vector.c				\
				./src/engine/utility/hmap/hmap_iterate.c					\
				./src/engine/utility/hmap/intern_hmap.c						\
				./src/engine/utility/hmap/hmap_construct.c					\
				./src/engine/utility/hmap/hmap_destruct.c					\
				./src/engine/utility/hmap/hmap_access.c						\
				./src/engine/utility/hmap/hmap_values.c						\
				./src/engine/utility/hmap/hmap_namespace.c					\
				./src/engine/message/queue.c

SRC			=	src/main.c			\
				$(ENGINE_SRC)

OBJ			=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

debug:			CFLAGS += -g
debug:			re

.PHONY:			all clean fclean re debug