##
## EPITECH PROJECT, 2018
## Engine
## File description:
## Makefile
##

NAME		=	OmegaEngine

ENGINE_PATH	=	./engine/src

GAME_PATH 	=	./game/src

CC			=	gcc

INCLUDE		=	-Iinclude -Iengine/include

CSFML		=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

MATH		=	-lm

CFLAGS  	=	-Wall -Wextra -std=c11 $(INCLUDE) $(CSFML) $(MATH)

VGCORE		=	vgcore*

SRC 		=	$(GAME_PATH)/Callbacks.c

ENGINE_SRC	=	$(ENGINE_PATH)/main.c																	\
				$(ENGINE_PATH)/Application.c															\
				$(ENGINE_PATH)/Component.c																\
				$(ENGINE_PATH)/DataStruct/Vector_namespace.c											\
				$(ENGINE_PATH)/DataStruct/Vector_internal.c												\
				$(ENGINE_PATH)/DataStruct/Vector_construct.c											\
				$(ENGINE_PATH)/DataStruct/Vector_destruct.c												\
				$(ENGINE_PATH)/DataStruct/Vector_find.c													\
				$(ENGINE_PATH)/DataStruct/Vector_data.c													\
				$(ENGINE_PATH)/DataStruct/Vector_mutation.c												\
				$(ENGINE_PATH)/DataStruct/Vector_iterate.c

ENGINE_OBJ	=	$(ENGINE_SRC:.c=.o)

OBJ			=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(ENGINE_OBJ) $(OBJ)
				$(CC) -o $(NAME) $(ENGINE_OBJ) $(OBJ) $(CFLAGS)
				@echo -e "\033[0;35mCompiling !\033[0m" 
				rm -f $(OBJ)

clean:
				rm -f $(OBJ) $(ENGINE_OBJ) $(VGCORE)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

debug:			CFLAGS += -g
debug:			re

.PHONY:			all clean fclean re debug