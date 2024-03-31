#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 if not or if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* If leaf node, return true */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If both left and right are not NULL, and both subtrees are full */
	if ((tree->left) && (tree->right))
		return (binary_tree_is_full(tree->left) &&
				binary_tree_is_full(tree->right));

	/* If neither of the above cases, it's not a full tree */
	return (0);
}
