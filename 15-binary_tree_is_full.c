#include "binary_trees.h"

/**
 * full_recursive - Function to checks if a binary tree is full recursively.
 * @tree: pointing to the root node of the tree to be checked.
 * Return: If tree is not full, 0. Otherwise, 1.
 */
int full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    full_recursive(tree->left) == 0 ||
		    full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Function to checks if a binary tree is full.
 * @tree: pointing to the root node of the tree to be checked.
 * Return: If tree is NULL or is not full, 0. Otherwise, 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (full_recursive(tree));
}
