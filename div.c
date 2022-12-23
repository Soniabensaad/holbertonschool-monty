#include "monty.h"

/**
 * div - divides the second top element of the stack
 * @stack: stack_t
 * @c: unsigned int
 */

void div(stack_t **stack, unsigned int c)
{
    stack_t *s, *temp;
    int i = 0, j = 0;

    s = *stack;
    if (s == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", c);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    while (s)
    {
        s = s->next;
        i++;
    }
    if (i < 2)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", c);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", c);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    temp = *stack;
    j = (*stack)->next->n / (*stack)->n;
    (*stack)->next->n = j;
    *stack = (*stack)->next;
    free(temp);
}