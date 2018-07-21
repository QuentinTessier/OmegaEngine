/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** data_list
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "engine.h"

void create_stack(render_stack *stack, size_t size)
{
	stack->max = size;
	stack->top = -1;
	stack->data = malloc(sizeof(void *) * size);
	stack->types = malloc(sizeof(data_type) * size);
	for (size_t i = 0; i < size; i++) {
		stack->data[i] = NULL;
		stack->types[i] = NO_DATA;
	}
}

int stack_full(render_stack *stack)
{
	if (stack->top == (int)stack->max - 1)
		return (1);
	return (0);
}

int stack_empty(render_stack *stack)
{
	if (stack->top == -1)
		return (1);
	return (0);
}

void push(render_stack *stack, void *data, data_type type)
{
	if (stack_full(stack) == 1) {
		write(2, "Rendering_Stack is full you need to alloc more space\n", 53);
		return;
	}
	stack->top++;
	stack->data[stack->top] = data; 
	stack->types[stack->top] = type; 
}

render_info pop(render_stack *stack)
{
	render_info info;

	info.type = NO_DATA;
	if (stack_empty(stack) == 1)
		return (info);
	info.data = stack->data[stack->top];
	stack->data[stack->top] = NULL;
	info.type = stack->types[stack->top];
	stack->types[stack->top] = NO_DATA;
	stack->top--;
	return (info);
}