#include "monty.h"

/**
 * add_to_stack - add a new node toe the stack stucture
 *
 * @head: the head of the stack
 * @value: the value to be added
 */
void add_to_stack(stack_t **head, int value)
{
	stack_t *temp;

	temp = (stack_t *)malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	temp->next = *head;
	(*head)->prev = temp;
	temp->prev = NULL;
	temp->n = value;
	*head = temp;
}

/**
 * create_1_node_stack - create a new node stack at the beginning
 *
 * @n: the value to be added to the first node stack
 *
 * Return: the new node pointer
 */
stack_t *create_1_node_stack(int n)
{
	stack_t *temp;

	temp = (stack_t *)malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	temp->prev = NULL;
	temp->n = n;
	temp->next = NULL;

	return (temp);
}

/**
 * line_ops - function that takes the line from the file and parse it
 *
 * @line: the line to parse
 * @line_number: the line number in the file giving as an argument
 * @head: the head of the stack
 */
void line_ops(char *line, unsigned int line_number, stack_t **head)
{
	char *tmp = NULL;
	void (*f)(stack_t **stack, unsigned int line_number);
	static int first_op = 1;

	if (line_number == 0)
	{
		free_nodes(head);
		return;
	}
	if (line[0] == '\n' || check_if_spaces(line))
	{
		return;
	}
	tmp = _strCopy(strtok(line, " \n"));
	if (strcmp(tmp, "push") == 0)
	{
		free(tmp);
		tmp = NULL;
		tmp = _strCopy(strtok(NULL, " \n"));
		if (atoi(tmp) == 0 && tmp[0] != '0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_nodes(head);
			free(tmp);
			exit(EXIT_FAILURE);
		}
		if (first_op == 1)
		{
			*head = create_1_node_stack(atoi(tmp));
			first_op++;
		}
		else
			add_to_stack(head, atoi(tmp));
	}
	else
	{
		f = comparing_with_instruction(tmp);
		f(head, line_number);
	}
	free(tmp);
}

/**
 * open_file - open a file and take line by line
 *
 * @filename: the name of the file the get in monty
 *
 * Return: 0 on success
 */
int open_file(char *filename)
{
	FILE *fd;
	stack_t *head = NULL;
	char buffer[BUFFER_SIZE];
	unsigned int line_number = 0;

	fd = fopen(filename, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, BUFFER_SIZE, fd) != NULL)
	{
		++line_number;
		line_ops(buffer, line_number, &head);
	}
	line_ops(buffer, 0, &head);
	fclose(fd);
	return (0);
}

/**
 * comparing_with_instruction - compare the given instruction in the file
 *
 * @_1_tok: the first instruction token 1
 *
 * Return: pointer to a function
 */
void (*comparing_with_instruction(char *_1_tok))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t array_of_instr_funcs[] = {
		{"pop", pop_stack},
		{"pall", print_stack},
		{NULL, NULL}};

	while (array_of_instr_funcs[i].opcode != NULL)
	{
		if (strcmp(_1_tok, array_of_instr_funcs[i].opcode) == 0)
		{
			return (array_of_instr_funcs[i].f);
		}
		i++;
	}
	return (NULL);
}
