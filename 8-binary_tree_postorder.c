#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)  /* Handle empty tree/invalid function pointer */
		return;

	/* Recursively traverse left subtree */
	binary_tree_postorder(tree->left, func);

	/* Recursively traverse right subtree */
	binary_tree_postorder(tree->right, func);

	/* Process current node value last (post-order) */
	func(tree->n);
}
