#include "monty.h"

/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: the stack pointer to the head
 * @line_number: op line number
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_nodes - Adds the top two elements of the stack.
 * @stack: the stack pointer to the head
 * @line_number: op line number
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nodes - Adds the top two elements of the stack.
 * @stack: the stack pointer to the head
 * @line_number: op line number
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * print_char - Prints the Ascii value.
 * @stack: the stack pointer to the head
 * @line_number: op line number
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int char_value;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty", line_number);
		exit(EXIT_FAILURE);
	}

	char_value = (*stack)->n;
	if (char_value < 0 || char_value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", char_value);
}

/**
 * print_str - Prints a string.
 * @stack: the stack pointer to the head
 * @line_number: op line number
 */
void print_str(stack_t **stack, unsigned int line_number)
{
	int char_value;
	stack_t *tmp;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		char_value = tmp->n;
		if (char_value <= 0 || char_value > 127)
			break;
		printf("%c", char_value);
		tmp = tmp->next;
	}
	printf("\n");
}
