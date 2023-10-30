#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t - Function to stores recursively each level in an array of strings
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @buf: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **buf)
{
	char b[6];
	int width, left, right, is_left, i;

	if (!tree)
		return (0);
	to_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, buf);
	right = print_t(tree->right, offset + left + width, depth + 1, buf);
	for (i = 0; i < width; i++)
		buf[depth][offset + left + i] = b[i];
	if (depth && to_left)
	{
		for (i = 0; i < width + right; i++)
			buf[depth - 1][offset + left + width / 2 + i] = '-';
		buf[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !to_left)
	{
		for (i = 0; i < left + width; i++)
			buf[depth - 1][offset - width / 2 + i] = '-';
		buf[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - Measures the height of a binary tree
 * @tree: Pointer to the node to measures the height
 * Return: The height of the tree starting at  the node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_left;
	size_t height_right;

	height_left = tree->left ? 1 + _height(tree->left) : 0;
	height_right = tree->right ? 1 + _height(tree->right) : 0;
	return (height_left > height_right ? height_left : height_right);
}

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **buf;
	size_t height, i, j;

	if (!tree)
		return;
	height = _height(tree);
	buf = malloc(sizeof(*buf) * (height + 1));
	if (!buf)
		return;
	for (i = 0; i < height + 1; i++)
	{
		buf[i] = malloc(sizeof(**buf) * 255);
		if (!buf[i])
			return;
		memset(buf[i], 32, 255);
	}
	print_t(tree, 0, 0, buf);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (buf[i][j] != ' ')
				break;
			buf[i][j] = '\0';
		}
		printf("%s\n", buf[i]);
		free(buf[i]);
	}
	free(buf);
}
