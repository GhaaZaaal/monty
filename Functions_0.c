#include "monty.h"
/**
 * free_nodes - free all nodes
 *
 * @stack: the structure holding the allocated memory to be freed
 */
void free_nodes(stack_t **stack)
{
	stack_t *tmp;

	if (*stack == NULL)
		return;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
/**
 * _strCopy - copy a string to a new allocated terminated string
 *
 * @s: the string to copy
 *
 * Return: pointer to the new string
 */
char *_strCopy(char *s)
{
	int len = 0;
	char *copy = NULL;

	if (s == NULL)
		return (NULL);

	len = strlen(s);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	strcpy(copy, s);
	copy[len] = '\0';

	return (copy);
}
/**
 * print_stack - print a the nodes in the stack
 *
 * @head: the head of the stack
 * @line_number: the line number in the file giving as an argument
 */
void print_stack(stack_t **head,  unsigned int line_number)
{
	stack_t *copy = NULL;
	(void)line_number;

	copy = *head;
	while (copy != NULL)
	{
		printf("%d\n", copy->n);
		copy = copy->next;
	}
}
/**
 * pop_stack - pop the lifo stack
 *
 * @stack: the stack to pop
 * @line_number: the line number in the file giving as an argument
 */
void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}
