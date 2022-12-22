#include "monty.h"

/**
 * p_pop - removes the top element of the stack
 * @stack: stack_t
 * @count: unsigned int
 */

void p_pop(stack_t **stack, unsigned int count)
{
	stack_t *h;

	h = *stack;
	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		free(*stack);
		h = h->next;
		*stack = h;
	}
}