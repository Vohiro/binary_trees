#include "binary_trees.h"

/**
 * binary_trees_ancestor - Function to finds the lowest common ancestor of two nodes.
 * @first: Pointing to the first node.
 * @second: Pointing to the second node.
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *momn, *popn;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	momn = first->parent, popn = second->parent;
	if (first == popn || !momn || (!momn->parent && popn))
		return (binary_trees_ancestor(first, popn));
	else if (momn == second || !popn || (!popn->parent && momn))
		return (binary_trees_ancestor(momn, second));
	return (binary_trees_ancestor(momn, popn));
}
