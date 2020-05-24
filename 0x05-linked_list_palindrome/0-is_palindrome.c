#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_node - add new node at the beginning of a list
 * @head: pointer to head of the list
 * @n: number to add in node
 * Return: The address of the new element or NULL
 */
listint_t *add_node(listint_t **head, int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	else
	{
		new->n = n;
		new->next = *head;
	}
	*head = new;
	return (new);
}

/**
 * reverse_listint - reverse list
 * @head: pointer to the head of the list
 * Return: address new head
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *p, *se;

	p = NULL;
	if (*head == NULL)
		return (NULL);
	while (*head != NULL)
	{
		se = (*head)->next;
		(*head)->next = p;
		p = *head;
		(*head) = se;
	}
	*head = p;
	return (*head);
}

/**
 * list_len - print number of  elements of a list
 * @h: head of the list
 * Return: NUmber of nodes
 */
size_t list_len(const listint_t *h)
{
	int leng = 0;

	while (h != NULL)
	{
		h = h->next;
		leng++;
	}
	return (leng);
}

/**
 * is_palindrome - function to check if a single linked list is a palindrome
 * @head: pointer to head of the list
 * Return: 1 if it is or 0 if it is not a palindrome
 */
int is_palindrome(listint_t **head)
{
	int len = 0, mid = 0, pos = 1;
	listint_t *temp = *head, *temp2 = NULL;

	len = list_len(*head);
	if (len == 0)
		return (1);
	if (len % 2 == 0)
		mid = len / 2;
	else
		mid = (len + 1) / 2;
	/* printf("%d\n", mid); */
	while (temp != NULL)
	{
		if (pos == mid)
		{
			temp2 = reverse_listint(&temp);
			temp = *head;
		}
		if (temp2)
		{
			if (temp2->n != temp->n)
			{
				return (0);
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
		pos++;
	}
	return (1);
}
