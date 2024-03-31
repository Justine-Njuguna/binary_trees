#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)  /* Handle empty tree */
		return;

	/* Recursively delete left & right subtrees (post-order traversal) */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	/* Free the current node's memory */
	free(tree);
}
