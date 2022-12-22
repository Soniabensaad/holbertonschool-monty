#include "monty.h"

void st_push(stack_t **stack, unsigned int counter)
{
    int n, i = 0, z;

    if (tok)
    {
        if (tok[0] == '-')
            i++;
        for (; tok[i] != '\0'; i++)
        {
            if (tok[i] > '9' || tok[i] < '0')
            {
                z = 1;
            }
        }
        if (z == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            free_stack(*stack);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    n = atoi(tok);

    add_node(stack, n);
}
