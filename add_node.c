#include "monty.h"

/**
 * add_node - add node to the head stack
 * @stack: head of the stack
 * @tp: new_value
 */

void add_node(stack_t **stack, int tp)
{

	stack_t *node, *s;

	s = *stack;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("error\n");
		exit(0);
	}
	node->n = tp;
	node->next = *stack;
	node->prev = NULL;
	if (s)
		s->prev = node;
	*stack = node;
}
