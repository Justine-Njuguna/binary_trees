#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses a binary tree using in-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)  /* Handle empty tree/invalid function pointer */
		return;

	/* Recursively traverse left subtree first (in-order) */
	binary_tree_inorder(tree->left, func);

	/* Process current node value (in-order) */
	func(tree->n);

	/* Recursively traverse right subtree */
	binary_tree_inorder(tree->right, func);
}
