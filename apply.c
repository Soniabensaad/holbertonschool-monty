#include "monty.h"
/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: poiner to monty file
 * @content: line content
 * Return: no return
 */
int apply(char *c, stack_t **stack, unsigned int a, FILE *fp)
{

    instruction_t opst[] = {{"push", st_push},
                            {"pall", st_pall},
                            {NULL, NULL}};
    int i = 0;
    char *token;

    token = strtok(c, " \n\t");

    tok = strtok(NULL, " \n\t");

    while (opst[i].opcode && token)
    {
        if (strcmp(token, opst[i].opcode) == 0)
        {
            opst[i].f(stack, a);
            return (0);
        }
        i++;
    }
    if (token && opst[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", a, token);
        fclose(fp);
        free(c);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    return (1);
}
