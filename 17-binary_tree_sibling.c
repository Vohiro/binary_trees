#include "binary_trees.h"

/**
 * binary_tree_sibling - Function to finds the sibling of a
 *                       node in a binary tree.
 * @node: poining to the node to find the sibling.
 * Return: If node is NULL or there is no sibling.
 *         Otherwise - a pointer to the sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
