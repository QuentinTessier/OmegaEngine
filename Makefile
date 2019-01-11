##
## EPITECH PROJECT, 2018
## Engine
## File description:
## Makefile
##

NAME		=	OmegaEngine

ENGINE_PATH	=	./engine/src

CC			=	gcc

INCLUDE		=	-Iinclude -Iengine/include

CSFML		=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

MATH		=	-lm

CFLAGS  	=	-Wall -Wextra -std=c11 $(INCLUDE) $(CSFML) $(MATH)

ENGINE_SRC	=	$(ENGINE_PATH)/main.c 														\
				$(ENGINE_PATH)/core/drawable/OmDrawable.c 									\
				$(ENGINE_PATH)/core/drawable/OmDrawable_parser.c							\
				$(ENGINE_PATH)/core/renderer/OmRenderer.c 									\
				$(ENGINE_PATH)/core/event/OmEvent.c		 									\
				$(ENGINE_PATH)/data_structure/OmHash/OmHash_access.c						\
				$(ENGINE_PATH)/data_structure/OmHash/OmHash_values.c						\
				$(ENGINE_PATH)/data_structure/OmHash/OmHash_construct.c						\
				$(ENGINE_PATH)/data_structure/OmHash/OmHash_destruct.c						\
				$(ENGINE_PATH)/data_structure/OmHash/OmHash_iterate.c						\
				$(ENGINE_PATH)/data_structure/OmHash/OmHash_internal.c						\
				$(ENGINE_PATH)/data_structure/OmHash/OmHash_namespace.c						\
				$(ENGINE_PATH)/data_structure/OmVector/OmVector_iterate.c					\
				$(ENGINE_PATH)/data_structure/OmVector/OmVector_mutation.c					\
				$(ENGINE_PATH)/data_structure/OmVector/OmVector_destruct.c					\
				$(ENGINE_PATH)/data_structure/OmVector/OmVector_set.c						\
				$(ENGINE_PATH)/data_structure/OmVector/OmVector_find_item.c					\
				$(ENGINE_PATH)/data_structure/OmVector/OmVector_namespace.c					\
				$(ENGINE_PATH)/data_structure/OmVector/OmVector_access.c					\
				$(ENGINE_PATH)/data_structure/OmVector/OmVector_internal.c					\
				$(ENGINE_PATH)/data_structure/OmVector/OmVector_construct.c					\
				$(ENGINE_PATH)/data_structure/OmStateMachine/OmStateMachine_namespace.c 	\
				$(ENGINE_PATH)/data_structure/OmStateMachine/OmStateMachine.c 				\
				$(ENGINE_PATH)/data_structure/OmPool/OmPool_namespace.c 					\
				$(ENGINE_PATH)/data_structure/OmPool/OmPool.c

ENGINE_OBJ	=	$(ENGINE_SRC:.c=.o)

SRC			=	./game_src/base_engine_func.c

OBJ			=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(ENGINE_OBJ) $(OBJ)
				$(CC) -o $(NAME) $(ENGINE_OBJ) $(OBJ) $(CFLAGS)
				rm -f $(OBJ)

clean:
				rm -f $(OBJ) $(ENGINE_OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

debug:			CFLAGS += -g
debug:			re

.PHONY:			all clean fclean re debug