#include "binary_trees.h"
#define MAX(a, b)  ((a) > (b) ? (a) : (b))

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)  /* Handle empty tree */
		return (0);

	/* Recursively find heights of left and right subtrees */
	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	/* Return the height of the taller subtree + 1 (for current node) */
	return (MAX(left_height, right_height) + 1);
}
