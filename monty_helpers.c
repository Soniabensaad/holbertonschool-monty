#include "monty.h"

/**
 * verify_args - verify the args
 * @argc: arguments
 * Return: 0 in succes -1 in fail
 */

void verify_args(int argc)
{
	if (argc > 2 || argc < 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * open_and_read - open the monty file and read his content
 * @f: the file to open
 * Return: Void no return
 */
void open_and_read(char *f)
{
	size_t l = 0;
	ssize_t r;
	unsigned int ln = 1;
	int value;
	char *op, *val, *opcode;

	file.fp = fopen(f, "r");
	if (file.fp == NULL)
		error_handler(f, -96, ln);
	while ((r = getline(&file.line, &l, file.fp)) != -1)
	{
		op = strtok(file.line, " ");
		if (*op == '#' || *op == '\n')
		{
			ln++;
			continue;
		}
		val = strtok(NULL, " \n");
		opcode = strtok(op, " \n");
		if (strcmp(opcode, "push") == 0)
		{
			if (is_number(val) && val != NULL)
			{
				value = atoi(val);
				if (!file.queue)
					apply_stack(&file.stack, value);
				else
					apply_queue(&file.stack, value);
			}
			else
				error_handler(opcode, -129, ln);
		} else
		{
			apply_monty(&file.stack, opcode, ln);
		}
		ln++;
	}
}
/**
 * apply_monty - execute the opcode funcion
 * @stack: head of the stack
 * @opcode: opcode instruction
 * @ln: number of line
 */
void apply_monty(stack_t **stack, char *opcode, int ln)
{
	int i;
	char *op;
	instruction_t instructions[] = {
		{"pall", apply_pall},
		{"pint", apply_pint},
		{"pop",apply_pop},
		{"swap", apply_swap},
		{"nop",apply_nop},
		{"pchar", apply_pchar},
		{"pstr", apply_pstr},
		{"add", apply_add},
		{"sub", apply_sub},
		{"mul", apply_mul},
		{"div", apply_div},
		{"mod", apply_mod},
		{"rotl", apply_rotl},
		{"rotr", apply_rotr},
		{"stack", apply_stack},
		{"queue",apply_queue},
		{NULL, NULL}
	};
	op = strtok(opcode, " \n");
	for (i = 0; instructions[i].opcode; i++)
		if (strcmp(op, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, ln);
			return;
		}
	error_handler(opcode, -128, ln);
}
/**
 * get - set initial values
 * Return: void
 */
void get(void)
{
	file.fp = NULL;
	file.line = NULL;
	file.stack = NULL;
	file.queue = false;
}
/**
 * total_free - clean men
 * Return: void
 */
void total_free(void)
{
	fclose(file.fp);
	free(file.line);
	fstack(file.stack);
}

