#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
 */
void st_pall(stack_t **stack, __attribute__((unused)) unsigned int count)
{
    stack_t *h;

    h = *stack;
    if (h == NULL)
        return;
    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}
