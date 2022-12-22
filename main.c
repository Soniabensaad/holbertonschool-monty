#include "monty.h"

/**
 * main - the big brain
 * @argc: int
 * @argv: char
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *cont;
	size_t size = 0;
	ssize_t read = 1;
	stack_t *stack = NULL;
	FILE *file;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		cont = NULL;
		read = getline(&cont, &size, file);
		count++;
		if (read > 0)
		{
			execute(cont, &stack, count);
		}
		free(cont);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}