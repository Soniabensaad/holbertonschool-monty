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

	settings.file = fopen(f, "r");
	if (settings.file == NULL)
		error_handler(f, -96, ln);
	while ((r = getline(&settings.line, &l, settings.file)) != -1)
	{
		op = strtok(settings.line, " ");
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
				if (!settings.queue)
					push_stack(&settings.stack, value);
				else
					push_queue(&settings.stack, value);
			}
			else
				error_handler(opcode, -129, ln);
		} else
		{
			exec_monty(&settings.stack, opcode, ln);
		}
		ln++;
	}
}
/**
 * exec_monty - execute the opcode funcion
 * @stack: head of the stack
 * @opcode: opcode instruction
 * @ln: number of line
 */
void exec_monty(stack_t **stack, char *opcode, int ln)
{
	int i;
	char *op;
	instruction_t instructions[] = {
		{"pall", exec_pall},
		{"pint", exec_pint},
		{"pop", exec_pop},
		{"swap", exec_swap},
		{"nop", exec_nop},
		{"pchar", exec_pchar},
		{"pstr", exec_pstr},
		{"add", exec_add},
		{"sub", exec_sub},
		{"mul", exec_mul},
		{"div", exec_div},
		{"mod", exec_mod},
		{"rotl", exec_rotl},
		{"rotr", exec_rotr},
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
 * set - set initial values
 * Return: void
 */
void set(void)
{
	settings.file = NULL;
	settings.line = NULL;
}
/**
 * clean - clean men
 * Return: void
 */
void clean(void)
{
	fclose(settings.file);
	free(settings.line);
	fstack(settings.stack);
}

