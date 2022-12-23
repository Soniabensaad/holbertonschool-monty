#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: stack_t
 * @count: unsigned int
 */

void pall(stack_t **stack, __attribute__((unused)) unsigned int c)
{
	stack_t *s;

	s = *stack;
	if (s == NULL)
		return;
	while (s)
	{
		printf("%d\n", s->n);
		s = s->next;
	}
}
