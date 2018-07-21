/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** data_struct
*/

#ifndef DATA_STRUCT_H_
	#define DATA_STRUCT_H_

typedef enum Data_type {
	NO_DATA = -1,
	C_SPR
} data_type;

typedef struct render_info {
	data_type type;
	void *data;
} render_info;

typedef struct data_stack {
	data_type *types;
	void ** data;
	int top;
	unsigned int max;
} render_stack;

#endif /* !DATA_STRUCT_H_ */
