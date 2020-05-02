#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>
#include "binary_trees.h"
binary_tree_t *binary_tree_preorder(binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
binary_tree_t *verify_order(binary_tree_t *tree);
void plevel2(binary_tree_t *tree, int level, int value, int flag);

/**
 * heap_insert - Function to insert a node for a binary tree
 * @root: this is the head of our binary tree
 * @value: This is the value of each element in our binary tree
 * Return: pointer to new node or NULL if it fails
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL;
	binary_tree_t *parent = NULL;
	int height = 0;

	if (value)
	{
		if (*root)
		{
			height = binary_tree_height(*root);
			if (binary_tree_balance(*root) == 0)
			{
				puts("aqui entro");
				parent = binary_tree_preorder(*root);
				printf("parent value %d", parent->n);
				parent->left = binary_tree_node(parent, value);
				printf("esto es new %d\n",parent->left->n);
				new = parent->left;
				new = verify_order(parent->left);
				printf("esto es new %d\n",new->n);
			}
			else
			{
				puts("esta entrando por desbalance");
				plevel2(*root, height + 1, value, 0);
				puts("salgo bien");
				new = *root;

				printf("esto tiene new tree->n %d\n", new->n);
			}
		}
		else
		{
			*root = binary_tree_node(*root, value);
			new = *root;
		}
		return (new);
	}

	return (NULL);

}

/**
 * plevel - print node, especific level
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * @level: level to print
 */
void plevel2(binary_tree_t *tree, int level, int value, int flag)
{
	/* binary_tree_t *new = tree; */
        /* /\* *nr = tree->right; *\\/ *\/ */

	/* /\* if (level == 1) *\/ */
	/* /\* { *\/ */


	/* if (tree->left == NULL && tree->right == NULL && flag == 0) */
	/* { */
	/* 	flag = flag + 1; */
	/* 	tree->left = binary_tree_node(tree, level); */
	/* 	new = tree->left; */
	/* 	return (tree->left); */
	/* } */
	/* if (tree->left && tree->right == NULL && flag == 0) */
	/* { */
	/* 	flag = flag + 1; */
	/* 	tree->right = binary_tree_node(tree, level); */
	/* 	return (tree->right); */
	/* } */



	/* /\* } *\/ */
	/* /\* else *\/ */
	/* /\* { *\/ */
	/* if (tree->left) */
	/* 	plevel(tree->left, level, flag); */
	/* if (tree->right) */
	/* 	plevel(tree->right, level, flag); */
	/* if (height tree */
	/* printf("esto es null y flag %d",flag); */
	/* return (new); */

	binary_tree_t *nl = tree->left;
 /* *nr = tree->right; */
	int a = 0;

	if (level == 2)
	{
		printf("estos es el último de la penúltima %d %d",tree->n, value);
		if (tree->left == NULL && tree->right == NULL && flag == 0)
		{
			a = a + 1;
			tree->left = binary_tree_node(tree, value);
			verify_order(tree->left);
			flag = flag + 1;
		}
		else
		{
			if (tree->left && tree->right == NULL && flag == 0 && a == 0)
			{
				tree->right = binary_tree_node(tree, value);
				verify_order(tree->right);
				flag = flag + 1;
			}
		}
		flag = flag + 1;
	}
	else
	{
		if(tree->left)
			plevel2(nl, level - 1, value, flag);
		/* if(nr) */
		/* 	plevel2(nr, level - 1, value, flag); */
	}
	flag = flag + 1;

}

/**
 *binary_tree_height - measures the height of a binary tree
 *@tree: pointer to root node of the tree measure the height
 *Return: if tree is NULL return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height1 = 0, height2 = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	height1 = binary_tree_height(tree->left);
	height2 = binary_tree_height(tree->right);

	if (height1 < height2)
		return (height2 + 1);
	return (height1 + 1);
}

/**
 * binary_tree_preorder - This function prints preorder traversal a binary tree
 * @tree: root of tree
 * @func: pointer to a function to call for each node
 * Return: It doesnt return anything
 */
binary_tree_t *binary_tree_preorder(binary_tree_t *tree)
{
	/* if (tree) */
	/* { */
 		/* func(tree->n); */
		/* depth = depth + 1; */
	if (tree->left)
	{
		return(binary_tree_preorder(tree->left));
		/* return(tree->left); */
	}
	return(tree);
}


/**
 * verify_order - returns node position
 * @tree: root of tree
 * Return: returns the balance
 */
binary_tree_t *verify_order(binary_tree_t *tree)
{
	int temp = 0;

	if (tree->parent)
	{
		if (tree->parent->n < tree->n)
		{
			temp = tree->n;
			tree->n = tree->parent->n;
			tree->parent->n = temp;
			verify_order(tree->parent);
		}
	}
	return (tree);
}

/**
 * binary_tree_balance - returns the balance (left - right) of the tree
 * @tree: root of tree
 * Return: returns the balance
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int l = -1;
	int r = -1;

	if (tree)
	{
		if (tree->left)
		{
			l = (binary_tree_balance(tree->left));
		}
		if (tree->right)
		{
			r = (binary_tree_balance(tree->right));
		}
		return (l - r);
	}
	return (0);
}
