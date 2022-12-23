#include "monty.h"
/**
 * apply_pall - this function executes the pall opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void apply_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	if (!stack || !(*stack))
		return;

	tmp = *stack;

	while (tmp->prev)
		tmp = tmp->prev;

	for (; tmp->next; tmp = tmp->next)
		printf("%d\n", tmp->n);

	printf("%d\n", tmp->n);
}
/**
 * apply_nop - this function executes the nop opcode does nothing jeje
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void apply_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * apply_pint - this function executes the pint opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void apply_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack;

	actual == NULL ? error_handler("pint", -98, line_number) : (void) actual;
	printf("%d\n", actual->n);
}
/**
 * apply_pop - this function executes the pop opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void apply_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	tmp == NULL ? error_handler("pop", -95, line_number) : (void) tmp;
	*stack = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;

	free(tmp);
}
/**
 * apply_swap - this function executes the swap opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void apply_swap(stack_t **stack, unsigned int line_number)
{
	int aux;
	stack_t *actual = *stack, *next;

	actual == NULL || actual->next == NULL ?
	error_handler("swap", -99, line_number) : (void) actual;
	next = actual->next;
	aux = actual->n;
	actual->n = next->n;
	next->n = aux;
}
