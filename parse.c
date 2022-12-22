#include "monty.h"

/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @count: line_counte
 * @cont: line content
 */

void apply(char *conter, stack_t **stack, unsigned int count)
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
							{NULL, NULL}};

	int i = 0;
	char *p;

	p = strtok(conter, delim);

	val = strtok(NULL, delim);
	if (p[0] == '#')
	{
		return;
	}
	while (opst[i].opcode && p)
	{
		if (strcmp(p, opst[i].opcode) == 0)
		{
			opst[i].f(stack, count);
			return;
		}
		i++;
	}
	if (p && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, p);
		free(conter);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}