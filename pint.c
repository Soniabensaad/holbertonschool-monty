#include "monty.h"
void pint(stack_t **stack, unsigned int line_number)
{
    stack_t *st;
    st = *stack;
    if (!st)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		clear_stack(*stack);
		clean_exit();
    }
    else
    {
        printf("%d\n", st->n);
    }
}