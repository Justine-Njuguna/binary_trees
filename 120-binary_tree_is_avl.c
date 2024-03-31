#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree.
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height, balance_factor;

	if (tree == NULL)
		return (0);

	/* Check if left and right subtrees are AVL trees */
	if (!binary_tree_is_avl(tree->left) ||
			!binary_tree_is_avl(tree->right))
		return (0);

	/* Get the height of left and right subtrees */
	left_height = height(tree->left);
	right_height = height(tree->right);

	/* Calculate the balance factor */
	balance_factor = left_height - right_height;

	/* Check if the current node is balanced and if it's a BST */
	if (abs(balance_factor) <= 1 && binary_tree_is_bst(tree))
		return (1);
	else
		return (0);
}
