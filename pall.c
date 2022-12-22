#include "monty.h"
/**

 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tpr;
    tpr = *stack;
    if (tpr == NULL)
    {
        return;
    }
    while (tpr)
    {
        printf("%d\n", tpr->n);
        tpr = tpr->next;
    }
    
}
