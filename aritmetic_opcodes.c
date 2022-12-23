#include "monty.h"
/**
 * apply_div - this function executes the div opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void apply_div(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;

	if (actual == NULL || actual->next == NULL)
		error_handler("div", -99, line_number);
	if (actual->n == 0)
		error_handler("div", -126, line_number);
	next = actual->next;
	next->n =  next->n / actual->n;
	apply_pop(stack, line_number);
}
/**
 * apply_mod - this function executes the mod opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void apply_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *next;

	if (current == NULL || current->next == NULL)
		error_handler("mod", -99, line_number);
	if (current->n == 0)
		error_handler("mod", -126, line_number);
	next = current->next;
	next->n =  next->n % current->n;
	apply_pop(stack, line_number);
}
/**
 * apply_add - this function executes the add opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void apply_add(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;

	if (actual == NULL || actual->next == NULL)
		error_handler("add", -99, line_number);
	next = actual->next;
	next->n =  next->n + actual->n;
apply_pop(stack, line_number);
}
/**
 * apply_sub - this function executes the div opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void apply_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;

	if (actual == NULL || actual->next == NULL)
		error_handler("sub", -99, line_number);
	next = actual->next;
	next->n =  next->n - actual->n;
	apply_pop(stack, line_number);
}
/**
 * apply_mul - this function executes the div opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void apply_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;

	if (actual == NULL || actual->next == NULL)
		error_handler("mul", -99, line_number);
	next = actual->next;
	next->n =  next->n * actual->n;
	apply_pop(stack, line_number);
}
