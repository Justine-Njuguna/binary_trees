#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes thru a binary tree using lvl-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	size_t h = binary_tree_height(tree);

	for (size_t i = 0; i <= h; i++)
		given_level(tree, i, func);
}

/**
 * given_level - Helper function to apply func to nodes at a given level
 * @tree: Pointer to the root node of the tree
 * @level: Level at which to apply func
 * @func: Pointer to a function to call for each node's value
 */
void given_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);

	else if (level > 0)
	{
		given_level(tree->left, level - 1, func);
		given_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}
