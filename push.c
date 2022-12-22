#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: top of stack_t stack
 * @line_number: current instruction line_number
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *valor, *line_dup;
	char *delim = " '\r''\n''\t'";
	stack_t *new_node = NULL;

	line_dup = strdup(st_tools.instructions);
	strtok(line_dup, delim);
	valor = strtok(NULL, delim);

	if (!is_numeric(valor) || valor == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(line_dup);
		clear_stack(*stack);
		clean_exit();
	}

	if (strcmp(st_tools.type, "queue") == 0)
		new_node = add_node_end(stack, atoi(valor));
	else
		new_node = add_node_head(stack, atoi(valor));

	if (new_node == NULL)
	{
		puts_stderr("Error: malloc failed\n");
		free(line_dup);
		clear_stack(*stack);
		clean_exit();
	}
	free(line_dup);
}

