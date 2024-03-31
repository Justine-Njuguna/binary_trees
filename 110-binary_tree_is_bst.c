#include "binary_trees.h"

/**
 * binary_tree_is_bst_helper - Recursive helper function for BST check
 * @tree: Pointer to the current node
 * @min_val: Minimum allowed value in the current subtree
 * @max_val: Maximum allowed value in the current subtree
 *
 * Return: 1 if current subtree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst_helper(const binary_tree_t *tree,
		long min_val, long max_val)
{
	if (!tree)  /* Base case: empty subtree is valid */
		return (1);

	if ((long)tree->n < min_val || (long)tree->n > max_val)
		/* Node value violates BST property*/
		return (0);

	/* Recursively check left subtree with updated max allowed value */
	return (binary_tree_is_bst_helper(tree->left,
				min_val, (long)tree->n - 1) &&
			binary_tree_is_bst_helper(tree->right,
				(long)tree->n + 1, max_val));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)  /* Base case: empty tree is not a BST */
		return (0);

	return (binary_tree_is_bst_helper(tree, LONG_MIN, LONG_MAX));
}
