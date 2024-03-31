#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the parent node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: A pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (!parent)  /* Check for invalid parent */
		return (NULL);

	/* Create the new node */
	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (!new_node)  /* Handle allocation failure */
		return (NULL);
	/* If there's an existing left child: */
	if (parent->left)
	{
		/* Make it the new node's left child */
		new_node->left = parent->left;

		/* Update the parent pointer of the old left child */
		parent->left->parent = new_node;
	}

	/* Set the new node as the parent's left child */
	parent->left = new_node;

	return (new_node);
}
