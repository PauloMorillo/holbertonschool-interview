#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Function to create a node for a binary tree
 * @parent: this is the head of our binary tree
 * @value: This is the value of each element in our binary tree
 * Return: pointer to new node or NULL if it fails
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	new->n = value;
	new->parent = parent;
	return (new);
}
