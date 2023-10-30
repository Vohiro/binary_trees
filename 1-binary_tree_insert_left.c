#include "binary_trees.h"

/**
 * binary_tree_insert_left - Function to Inserts a node as a left-child
 *                           of another in a binary tree.
 * @parent: pointer to the node to insert the left-child in.
 * @value: value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *create;

	if (parent == NULL)
		return (NULL);

	create = binary_tree_node(parent, value);
	if (create == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		create->left = parent->left;
		parent->left->parent = create;
	}
	parent->left = create;

	return (create);
