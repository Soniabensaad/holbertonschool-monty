#include "monty.h"
int remove_node_start(stack_t **head, stack_t *current_node)
{
	stack_t *tmp;

	if (!current_node->next)
	{
		free(current_node);
		*head = NULL;
		return (1);
	}
	else
	{
		tmp = current_node->next;
		free(current_node);
		tmp->prev = NULL;
		*head = tmp;
		return (1);
	}
	return (-1);
}
