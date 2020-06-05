#include "lists.h"
/**
 * check_cycle - check if a list is a cycle or not
 * @list: struct
 * Return: 1 if is a cyrcle or 0
 */
int check_cycle(listint_t *list)
{
	/* listint_t **tempmem = NULL; */
	listint_t *temp = NULL, *temp2 = NULL;

	temp = list;
	/* tempmem = &list; */

	if (list == NULL)
		return (0);

	if (temp->next && temp->next->next)
		temp2 = temp->next->next;
	else
		return (0);

	while (temp2 != NULL)
	{
		/* if (temp == *(tempmem) ||  */
		if (temp == temp2)
			return (1);
		/* temp = temp->next; */
		if (temp2->next)
		{
			if (temp2->next->next)
				temp2 = temp2->next->next;
			else
				return (0);
		}
		else
			return (0);
		temp = temp->next;
	}
	return (0);
}
