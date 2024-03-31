#include "binary_trees.h"

/**
 * depth - Measures the depth of a node in a binary tree
 * @node: Pointer to the node to measure the depth
 *
 * Return: The depth of the node from the root
 */
size_t depth(const binary_tree_t *node)
{
	size_t d = 0;

	while (node != NULL)
	{
		d++;
		node = node->parent;
	}
	return (d);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes,
 *         or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t depth_first = depth(first);
	size_t depth_second = depth(second);
	size_t diff;

	/* Make first point to the deeper node */
	if (depth_second > depth_first)
	{
		const binary_tree_t *temp = first;

		first = second;
		second = temp;
		diff = depth_second - depth_first;
	}
	else
	{
		diff = depth_first - depth_second;
	}

	/* Move up the tree to the same level as the shallower node */
	while (diff--)
		first = first->parent;

	/* Find the common ancestor */
	while (first != NULL && second != NULL)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}

	return (NULL); /* No common ancestor */
}
