#include "list.h"
/**
 * insert - insert first node
 * @list: circular linked list
 * @str: string (malloc'ed string)
 * Return: new node, or if null if it fails
 */
List *insert(List **list, char *str)
{
	List *new_node;

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(str);
		return (NULL);
	}

	new_node->next = new_node;
	new_node->prev = new_node;
	*list = new_node;

	return (new_node);
}

/**
 * add_node_begin - node at the top
 * @list: doubly linked list
 * @str: string - (malloc'ed string)
 * Return: new node, or if null if it fails
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node, *temp, *temp2;

	if (list == NULL)
		return (NULL);

	if (*list == NULL)
		return (insert(list, str));

	temp2 = *list;
	new_node = malloc(sizeof(List));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = temp2;
	new_node->prev = temp2->prev;
	temp = temp2->prev;
	temp2->prev = new_node;
	temp->next = new_node;
	*list = new_node;

	return (new_node);
}

/**
 * add_node_end - node at last position
 * @list: doubly linked list
 * @str: string (malloc'ed string)
 * Return: new node, or NULL if it fails
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *tmp, *temp2;

	if (list == NULL)
		return (NULL);

	if (*list == NULL)
		return (insert(list, str));

	temp2 = *list;
	new_node = malloc(sizeof(List));

	if (new_node == NULL)
		return (NULL);
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = temp2;
	new_node->prev = temp2->prev;
	tmp = temp2->prev;
	temp2->prev = new_node;
	tmp->next = new_node;

	return (new_node);
}
