#include <stdio.h>
#include <stdlib.h>
#include "search.h"
size_t count(skiplist_t *list);
/**
 * count - length of the list
 * @list: is a pointer to the head of the skip list to search in
 * Return: a pointer on the first node where value is located
 */
size_t count(skiplist_t *list)
{
	size_t n = 0;

	while (list->next != NULL)
	{
		n = n + 1;
		list = list->next;
	}
	return (n);
}

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: is a pointer to the head of the skip list to search in
 * @value:  is the value to search for
 * Return: a pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp = list;
	skiplist_t *temp2 = NULL;

	if (list == NULL)
		return (NULL);
	while (value >= temp->express->n)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       temp->express->index, temp->express->n);
		temp = temp->express;
		if (temp->express == NULL)
			break;
	}
	if (temp->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       temp->express->index, temp->express->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
		       temp->index, temp->express->index);
	}
	else
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
		       temp->index, count(list));
	}
	temp2 = temp;
	while (value >= temp2->next->n)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       temp2->index, temp2->n);
		/* if (value > temp->n) */
		temp2 = temp2->next;
		if (temp2->next == NULL)
			break;
	}
	printf("Value checked at index [%lu] = [%d]\n", temp2->index, temp2->n);
	if (temp2->next == NULL)
		return (NULL);
	return (temp2);
}
