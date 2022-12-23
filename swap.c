#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack_t
 * @c: unsigned int
 */

void swap(stack_t **stack, unsigned int c)
{
	stack_t *s;
	int i = 0, j;

	s = *stack;
	if (s == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", c);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	while (s)
	{
		s = s->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", c);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	j = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = j;
}
