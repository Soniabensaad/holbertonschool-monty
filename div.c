#include "monty.h"

/**
 * div - divides the second top element of the stack by the top element
 * of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: the number of the line in file
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int product;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	product = temp->next->n / temp->n;
	temp->next->n = product;

	*stack = temp->next;

	free(temp);
}
