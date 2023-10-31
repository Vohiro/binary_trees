#include "binary_trees.h"

/**
 * binary_tree_inorder - Function to go through a binary tree using in-order traversal.
 * @tree: pointing to the root node of the tree to be traversed.
 * @func: pointing to a function to call for each node.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
