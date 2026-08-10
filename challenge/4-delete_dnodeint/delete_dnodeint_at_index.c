#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	dlistint_t *tmp;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}

	current = *head;
	while (index > 0 && current != NULL)
	{
		current = current->next;
		index--;
	}
	if (current == NULL)
	{
		return (-1);
	}

	if (current->prev != NULL)
		current->prev->next = current->next;
	else
		*head = current->next;

	tmp = current->next;
	if (tmp != NULL)
		tmp->prev = current->prev;

	free(current);
	return (1);
}