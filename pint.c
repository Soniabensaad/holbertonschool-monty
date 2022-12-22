#include "monty.h"

/**
 * p_pint - prints the value at the top of the stack, followed by a new line
 * @stack: stack_t
 * @count: unsigned int
 */

void p_pint(stack_t **stack, unsigned int count)
{
	stack_t *h;

	h = *stack;
	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empt\n", count);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", h->n);
	}
}
