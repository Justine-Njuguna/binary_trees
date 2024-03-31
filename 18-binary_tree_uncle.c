#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL if node is NULL or has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
			node->parent->parent == NULL)
		return (NULL);

	/* If parent is the left child, uncle is the right child of granny */
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);

	/* If parent is the right child, uncle is the left child of granny */
	if (node->parent == node->parent->parent->right)
		return (node->parent->parent->left);

	return (NULL); /* Node has no uncle */
}