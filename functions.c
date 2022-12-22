#include "monty.h"
void stack(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	st_tools.type = "stack";
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: top of stack_t stack
 * @line_number: current instruction line number
 *
 * Return: absolutely nothing
 */
void queue(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	st_tools.type = "queue";
}
