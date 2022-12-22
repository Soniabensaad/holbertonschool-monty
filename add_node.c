#include "monty.h"
/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
 */
void add_node(stack_t **stack, int n)
{

    stack_t *new_node, *a;

    a = *stack;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("error\n");
        exit(0);
    }
    new_node->n = n;
    new_node->next = *stack;
    new_node->prev = NULL;
    if (a)
        a->prev = new_node;
    *stack = new_node;
}