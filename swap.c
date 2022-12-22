#include "monty.h"

/**
 * p_swap - swaps the top two elements of the stack
 * @stack: stack_t
 * @count: unsigned int
 */

void p_swap(stack_t **stack, unsigned int count)
{
	stack_t *h;
	int i = 0, a;

	h = *stack;
	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	while (h)
	{
		h = h->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = a;
}
