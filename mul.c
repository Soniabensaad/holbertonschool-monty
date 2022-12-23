#include "monty.h"

/**
 * mul-  multiplies the second top element of the stack 
 * @stack: stack_t
 * @count: unsigned int
 */

void mul(stack_t **stack, unsigned int c)
{
    stack_t *h, *z;
    int i = 0, a;

    h = *stack;
    if (h == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", c);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    while (h)
    {
        h = h->next;
        i++;
    }
    if (i < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", c);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    z = *stack;
    a = (*stack)->n * (*stack)->next->n;
    (*stack)->next->n = a;
    *stack = (*stack)->next;
    free(z);
}