#include "monty.h"

/**
 * p_pall - prints all the values on the stack
 * @stack: stack_t
 * @count: unsigned int
 */

void pall(stack_t **stack, __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}