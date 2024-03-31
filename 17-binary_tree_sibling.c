#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node, or NULL if node or parent is NULL,
 *         or if node has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Check if node is the left child of its parent */
	if (node->parent->left == node)
		return (node->parent->right); /* Return the right sibling */

	/* Check if node is the right child of its parent */
	if (node->parent->right == node)
		return (node->parent->left); /* Return the left sibling */

	return (NULL); /* Node has no sibling */
}
