#include "binary_trees.h"

/**
 * binary_tree_height - Helper function to measure the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
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

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 if not or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* Check if left and right subtrees are perfect and have the same height */
	if (left_height == right_height)
	{
		if (left_height == 0 || binary_tree_is_perfect(tree->left))
			return (binary_tree_is_perfect(tree->right));
	}
	return (0);
}
