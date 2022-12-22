#include "monty.h"

stack_t **value;

/**
 * monty - the root of the project
 * @argc: how many arguments were passed to a program
 * @argv: arguments vector
 *
 * Return: on scuccess, always EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	stack_t *stack;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stack = NULL;
	value = &stack;

	read_file(argv[1], &stack);

	atexit(global_free);

	exit(EXIT_SUCCESS);
}