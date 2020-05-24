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
	listint_t *temp = *head, *temp2 = NULL, *sec_half = NULL;

	len = list_len(*head);
	if (len % 2 == 0)
		mid = len / 2;
	else
		mid = (len + 1) / 2;
	/* printf("%d\n", mid); */
	while (temp != NULL)
	{
		if (pos >= mid)
			add_node(&sec_half, temp->n);
		temp = temp->next;
		pos++;
	}
	temp = *head;
	temp2 = sec_half;
	while (temp2->next != NULL)
	{
		/* printf("%d, %d\n", temp->n, temp2->n); */
		if (temp2->n != temp->n)
		{

			free_listint(sec_half);
			free_listint(temp2);
			return (0);
		}
		temp2 = temp2->next;
		temp = temp->next;
	}
	free_listint(sec_half);
	return (1);
}
