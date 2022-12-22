#include "monty.h"

/**
 * free_stack - free  stack
 * @stack: head of the stack
 */

void free_stack(stack_t *stack)
{
	stack_t *b;

	while (stack)
	{
		b = stack;
		stack = stack->next;
		free(b);
	}
}

