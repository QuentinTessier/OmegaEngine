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

LIBS		=	-L./engine/lib/ -ljsmn

CSFML		=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

MATH		=	-lm

CFLAGS  	=	-Wall -Wextra -std=c11 $(INCLUDE) $(CSFML) $(MATH) $(LIBS)

ENGINE_SRC	=	$(ENGINE_PATH)/main.c																	\
				$(ENGINE_PATH)/Application.c															\
				$(ENGINE_PATH)/DataStruct/Vector_namespace.c											\
				$(ENGINE_PATH)/DataStruct/Vector_internal.c												\
				$(ENGINE_PATH)/DataStruct/Vector_construct.c											\
				$(ENGINE_PATH)/DataStruct/Vector_destruct.c												\
				$(ENGINE_PATH)/DataStruct/Vector_find.c													\
				$(ENGINE_PATH)/DataStruct/Vector_data.c													\
				$(ENGINE_PATH)/DataStruct/Vector_mutation.c												\
				$(ENGINE_PATH)/DataStruct/Vector_iterate.c												\
				$(ENGINE_PATH)/Graphics/BufferVector/BufferVector_namespace.c							\
				$(ENGINE_PATH)/Graphics/BufferVector/BufferVector_internal.c							\
				$(ENGINE_PATH)/Graphics/BufferVector/BufferVector_construct.c							\
				$(ENGINE_PATH)/Graphics/BufferVector/BufferVector_destruct.c							\
				$(ENGINE_PATH)/Graphics/BufferVector/BufferVector_find.c								\
				$(ENGINE_PATH)/Graphics/BufferVector/BufferVector_data.c								\
				$(ENGINE_PATH)/Graphics/BufferVector/BufferVector_mutation.c							\
				$(ENGINE_PATH)/Graphics/BufferVector/BufferVector_iterate.c								\
				$(ENGINE_PATH)/Graphics/Buffers.c														\
				$(ENGINE_PATH)/Graphics/BufferPool.c

ENGINE_OBJ	=	$(ENGINE_SRC:.c=.o)

OBJ			=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(ENGINE_OBJ) $(OBJ)
				$(MAKE) -C ./engine/lib/
				$(CC) -o $(NAME) $(ENGINE_OBJ) $(OBJ) $(CFLAGS)
				rm -f $(OBJ)

clean:
				rm -f $(OBJ) $(ENGINE_OBJ)

fclean:			clean
				$(MAKE) -C ./engine/lib/ clean
				rm -f $(NAME)

re:				fclean all

debug:			CFLAGS += -g
debug:			re

.PHONY:			all clean fclean re debug