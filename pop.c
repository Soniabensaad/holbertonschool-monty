#include "monty.h"
void pop(stack_t **stack, unsigned int line_number)

{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		clear_stack(*stack);
		clean_exit();
	}
	remove_node_start(stack, *stack);
}