#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the parent node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: A pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	if (!parent)  /* Check for invalid parent */
		return (NULL);

	/* Create the new node */
	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (!new_node)  /* Handle allocation failure */
		return (NULL);

	/* If there's an existing right child: */
	if (parent->right)
	{
		/* Make it the new node's right child */
		new_node->right = parent->right;

		/* Update the parent pointer of the old right child */
		parent->right->parent = new_node;
	}

	/* Set the new node as the parent's right child */
	parent->right = new_node;

	return (new_node);
}
