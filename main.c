#include "monty.h"

/**
 * main - Monty program
 *
 * @argc: the arguments number
 * @argv: the program arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	return (0);
}
