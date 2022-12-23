#include "monty.h"

/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @c: line_counte
 * @count: line content
 */
void execute(char *count, stack_t **stack, unsigned int c)
{

	instruction_t opst[] = {{"push", push},
							{"pall", pall},
							{"pint", pint},
							{"pop", pop},
							{"swap", swap},
							{"add", add},
							{"nop", nop},
							{"sub", sub},
							{"div", div},
							{"mul", mul},
							{"mod", mod},
							{NULL, NULL}};

	int i = 0;
	char *p;

	p = strtok(count, DELIM);

	value = strtok(NULL, DELIM);
	if (p[0] == '#')
	{
		return;
	}
	while (opst[i].opcode && p)
	{
		if (strcmp(p, opst[i].opcode) == 0)
		{
			opst[i].f(stack, c);
			return;
		}
		i++;
	}
	if (p && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", c, p);
		free(count);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
