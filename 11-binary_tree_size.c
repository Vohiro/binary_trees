#include "binary_trees.h"

/**
 * binary_tree_size - Function to measures the size of a binary tree.
 * @tree: pointing to the root node of the tree to be measured.
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t s = 0;

	if (tree)
	{
		s += 1;
		s += binary_tree_size(tree->left);
		s += binary_tree_size(tree->right);
	}
	return (s);
}
