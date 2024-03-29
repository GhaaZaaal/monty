#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>

#define BUFFER_SIZE 128

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void free_nodes(stack_t **stack);
char *_strCopy(char *s);
void print_stack(stack_t **head, unsigned int line_number);
void pop_stack(stack_t **stack, unsigned int line_number);
int open_file(char *filename);
void line_ops(char *line, unsigned int line_number, stack_t **head);
void (*comparing_with_instruction(char *_1_tok))(stack_t **, unsigned int);
stack_t *create_1_node_stack(int n);
void add_to_stack(stack_t **head, int value);


#endif /* MONTY_H */
