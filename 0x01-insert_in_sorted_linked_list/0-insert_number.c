#include "lists.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * insert_node - insert new node in a single linked list
 * @head: pointer to go throughout list
 * @number: number to index in linked list
 * Return: new node or null
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *temp = NULL;
	listint_t *new = NULL;

	if (*head && number)
	{
		new = malloc(sizeof(listint_t));
		if (!new)
			return (NULL);
		new->n = number;

		temp = *head;
		while (temp->next != NULL)
		{
			if (number > temp->next->n)
				temp = temp->next;
			else
			{
				new->next = temp->next;
				temp->next = new;
				temp = temp->next;
				break;
			}
		}
		return (new);
	}
	return (NULL);
}
