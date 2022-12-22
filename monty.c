#include "monty.h"
/**
 * main - the big brain
 * @argc: int
 * @argv: char
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *conter;
	size_t size = 0;
	ssize_t readline = 1;
	stack_t *stack = NULL;
	FILE *f;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		conter = NULL;
		readline = getline(&conter, &size, f);
		count++;
		if (readline > 0)
		{
			execute(conter, &stack, count);
		}
		free(conter);
	}
	free_stack(stack);
	fclose(f);
	return (0);
}