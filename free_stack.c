#include "monty.h"
void free_stack(stack_t *stack)
{
    stack_t *st;

    while (stack)
    {
        st = stack;
        stack = stack->next;
        free(st);
    }
}
