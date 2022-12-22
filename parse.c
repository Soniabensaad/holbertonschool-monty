#include "monty.h"

/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @count: line_counte
 * @cont: line content
 */

void execute(char *cont, stack_t **stack, unsigned int count)
{

	instruction_t opst[] = {{"push", p_push},
							{"pall", p_pall},
							{"pint", p_pint},
							{"pop", p_pop},
							{NULL, NULL}};

	int i = 0;
	char *op;

	op = strtok(cont, " \n\t");

	val = strtok(NULL, " \n\t");
	if (op[0] == '#')
	{
		return;
	}
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, count);
			return;
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		free(cont);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}