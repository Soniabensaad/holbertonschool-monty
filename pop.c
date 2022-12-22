#include "monty.h"

/**
 * p_pop - removes the top element of the stack
 * @stack: stack_t
 * @count: unsigned int
 */

void pop(stack_t **stack, unsigned int counter)
{
	stack_t *s;

	s = *stack;
	if (s == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		free(*stack);
		s = s->next;
		*stack = s;
	}
}