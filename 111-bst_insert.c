#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent = NULL;
	bst_t *current;
	bst_t *new_node;

	if (!tree)
		return (NULL);

	/* Find the right place in the tree for the new value */
	current = *tree;
	while (current)
	{
		parent = current;
		if (value < current->n)
			current = current->left;

		else if (value > current->n)
			current = current->right;

		else
			/* Value is already present in the tree */
			return (NULL);
	}

	/* Create a new node */
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	/* Insert the new node at the right place */
	if (!parent)
		*tree = new_node; /* The tree was empty, new node == root */

	else if (value < parent->n)
		parent->left = new_node;

	else
		parent->right = new_node;

	return (new_node);
}
