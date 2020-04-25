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

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;

	temp = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (temp != NULL)
		{
			if (temp->next != NULL && (number > temp->next->n))
				temp = temp->next;
			else
			{
				new->next = temp->next;
				temp->next = new;
				temp = temp->next;
				break;
			}
		}
	}
	return (new);
}
