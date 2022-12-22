#include "monty.h"
void apply(unsigned int *number_line, stack_t **stack)
{
    char *line_duplicate, *tok;
    char *delim = " '\r''\n''\t'";
    void(*instruction_l)(stack_t **stack, unsigned int number_line);
    line_duplicate = strdup(st_tools.instructions);
    tok = strtok(line_duplicate, delim);
    if (tok)
    {
        *number_line += 1 ;
        if (tok[0] == '#')
        {
            instruction_l = help_instruction("#");
        }
        else
        {
            instruction_l = help_instruction(tok);
        }
        if (instruction_l == NULL)
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", *number_line, tok);
			free(line_duplicate);
			clear_stack(*stack);
			clean_exit();
        }
        free(line_duplicate);
        instruction_l(stack, *number_line);

    }
    else
    {
        if (*number_line > 0)
        {
            *number_line += 1;
        }
        free(line_duplicate);
    }
}
/*
*/
void (*help_instruction(char *command))(stack_t ** stack, unsigned int number_line)
{
    int a = 0;
	instruction_t opts[] = 
    {
		{"push", push},
		{"pall", pall},
        {"pint", pint},
		{"pop", pop},
        {NULL, NULL}};
    if (!command)
    {
        return (NULL);
    }
    while (opts[a].opcode != NULL)
    {
        if (strcmp(command, opts[a].opcode) == 0)
        {
            return (opts[a].f);
            a++;
        }
    }
    return (NULL);
    

}