#include "binary_trees.h"

unsigned char leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * leaf - Function to checks if a node is a leaf of a binary tree.
 * @node: pointing to the node to be checked.
 * Return: If the node is a leaf, 1, otherwise, 0.
 */
unsigned char leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Function to measure the depth of a given node in a binary tree.
 * @tree: pointing to the node to be measured.
 * Return: depth of node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Function that returns a leaf of a binary tree.
 * @tree: pointing to the root node of the tree to find a leaf in.
 * Return: returning to the first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * perfect_recursive - Function to hecks if a binary tree is perfect recursively.
 * @tree: pointing to the root node of the tree to check.
 * @leaf_depth: depth of one leaf in the binary tree.
 * @lvl: Level of current node.
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t lvl)
{
	if (leaf(tree))
		return (lvl == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (perfect_recursive(tree->left, leaf_depth, lvl + 1) &&
		perfect_recursive(tree->right, leaf_depth, lvl + 1));
}

/**
 * binary_tree_is_perfect - Function to checks if a binary tree is perfect.
 * @tree: pointing to the root node of the tree to check.
 * Return: If tree is NULL or not perfect, 0. Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
