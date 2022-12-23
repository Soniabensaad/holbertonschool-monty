#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: stack_t
 * @c: unsigned int
 */

void push(stack_t **stack, unsigned int c)
{
	int tp, i = 0, j;

	if (value)
	{
		if (value[0] == '-')
			i++;
		for (; value[i] != '\0'; i++)
		{
			if (value[i] > '9' || value[i] < '0')
			{
				j = 1;
			}
		}
		if (j == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", c);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", c);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tp = atoi(value);

	add_node(stack, tp);
}
