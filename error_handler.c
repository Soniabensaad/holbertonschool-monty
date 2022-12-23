#include "monty.h"
/**
 * error_handler - this function executes the div opcode
 * @op: opcode generates error
 * @code: the number of the error
 * @ln: number of line that is executed
 * Return: void function
 */
void error_handler(char *op, int code, int ln)
{
	if (code == -95)
	{dprintf(STDERR_FILENO, "L%u: can't %s an empty stack\n", ln, op);
		total_free();
		exit(EXIT_FAILURE);
	}
	if (code == -96)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", op);
		exit(EXIT_FAILURE);
	}
	if (code == -97)
	{
		dprintf(STDERR_FILENO, "Error: %s failed\n", op);
		total_free();
		exit(EXIT_FAILURE);
	}
	if (code == -98)
	{
		dprintf(STDERR_FILENO, "L%u: can't %s, stack empty\n", ln, op);
		total_free();
		exit(EXIT_FAILURE);
	}
	if (code == -99)
		dprintf(STDERR_FILENO,
		"L%u: can't %s, stack too short\n", ln, op), total_free(), exit(EXIT_FAILURE);
	if (code == -126)
		dprintf(STDERR_FILENO,
		"L%u: division by zero\n", ln), total_free(), exit(EXIT_FAILURE);
	if (code == -127)
		dprintf(STDERR_FILENO,
		"L%u: can't %s, value out of range\n", ln, op), total_free(), exit(EXIT_FAILURE);
	if (code == -128)
		dprintf(STDERR_FILENO,
		"L%d: unknown instruction %s\n", ln, op), total_free(), exit(EXIT_FAILURE);
	if (code == -129)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", ln);
		total_free();
		exit(EXIT_FAILURE);
	}
}
