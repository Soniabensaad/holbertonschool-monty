#include "monty.h"

/**
 * p_pint - prints the value at the top of the stack, followed by a new line
 * @stack: stack_t
 * @count: unsigned int
 */

void pint(stack_t **stack, unsigned int counter)
{
	stack_t *s;

	s = *stack;
	if (s == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empt\n", counter);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", s->n);
	}

}