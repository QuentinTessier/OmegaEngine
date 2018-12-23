##
## EPITECH PROJECT, 2018
## Engine
## File description:
## Makefile
##

NAME		=	OmegaEngine

CC			=	gcc

INCLUDE		=	-Iinclude -Iengine/include

CSFML		=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

MATH		=	-lm

CFLAGS  	=	-Wall -Wextra -std=c11 $(INCLUDE) $(CSFML) $(MATH)

RENDERER_SRC	=	./engine/renderer/renderer.c			\
					./engine/renderer/drawable.c

UTILITY_SRC	=	./engine/utility/vector/vector_construct.c 			\
					./engine/utility/vector/vector_destruct.c 			\
					./engine/utility/vector/internal_vector.c 			\
					./engine/utility/vector/vector_mutation.c  			\
					./engine/utility/vector/vector_find_item.c 			\
					./engine/utility/vector/vector_access.c     		\
					./engine/utility/vector/vector_iterate.c  			\
					./engine/utility/vector/vector_set.c				\
					./engine/utility/vector/vector_namespace.c			\
					./engine/utility/hmap/hmap_iterate.c				\
					./engine/utility/hmap/intern_hmap.c					\
					./engine/utility/hmap/hmap_construct.c				\
					./engine/utility/hmap/hmap_destruct.c				\
					./engine/utility/hmap/hmap_access.c					\
					./engine/utility/hmap/hmap_values.c					\
					./engine/utility/hmap/hmap_namespace.c				\
					./engine/utility/pool/pool.c 						\
					./engine/utility/pool/pool_namespace.c


SRC			=	src/main.c			\
				$(RENDERER_SRC)

OBJ			=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
				rm -f $(OBJ)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

debug:			CFLAGS += -g
debug:			re

.PHONY:			all clean fclean re debug