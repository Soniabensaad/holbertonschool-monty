#include "monty.h"
/**
 * apply_pchar - this function executes the pchar opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void apply_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack;

	actual == NULL ? error_handler("pchar", -98, line_number) : (void) actual;
	actual->n < 0 || actual->n > 127 ?
	error_handler("pchar", -127, line_number) : (void)actual;
	putchar(actual->n);
	putchar('\n');
}
/**
 * apply_pstr - this function executes the pstr opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void apply_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack;
	(void) line_number;
	while (actual)
	{
		if ((actual->n > 0) && actual->n < 127)
		{
			putchar(actual->n);
			actual = actual->next;
		} else
			break;
	}
	putchar('\n');
}
