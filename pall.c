#include "monty.h"

/**
 * p_pall - prints all the values on the stack
 * @stack: stack_t
 * @count: unsigned int
 */

void p_pall(stack_t **stack, __attribute__((unused)) unsigned int count)
{
	stack_t *h;

	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
