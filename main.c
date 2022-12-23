#include "monty.h"

/**
 * main - the big brain
 * @argc: int
 * @argv: char
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *count;
	size_t size = 0;
	ssize_t readline = 1;
	stack_t *stack = NULL;
	FILE *file;
	unsigned int c = 0;

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
		count = NULL;
		readline = getline(&count, &size, file);
		c++;
		if (read > 0)
		{
			execute(count, &stack, c);
		}
		free(count);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}