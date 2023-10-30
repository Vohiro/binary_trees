#include "binary_trees.h"

/**
 * binary_tree_node - Function to creates a binary tree node.
 * @parent: pointer to the parent of the node to create.
 * @value: value to put in the new node.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *create;

	create = malloc(sizeof(binary_tree_t));
	if (create == NULL)
		return (NULL);

	create->n = value;
	create->parent = parent;
	create->left = NULL;
	create->right = NULL;

	return (create);
}
