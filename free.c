#include "monty.h"

/**
 * free_all - globally frees memory, previously alocated in the program
 *
 * Return: void
 */
void global_free(void)
{
	stack_t *free_all;
	stack_t *temp = NULL;

	free_all = *value;

	while (free)
	{
		temp = free_all->next;

		free(free_all);

		free_all = temp;
	}
}