#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 if not or if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	bool full = true;
	bool end = false;
	size_t size = binary_tree_size(tree);

	for (size_t index = 0; index < size; index++)
	{
		if (!is_node_present(tree, index, size))
		{
			full = false;
			break;
		}

		if (end && is_node_present(tree, index, size))
		{
			full = false;
			break;
		}

		if (!tree->left || !tree->right)
			end = true;
	}

	return (full);
}

/**
 * is_node_present - Checks if a node is present at an
 *		index in a complete binary tree
 * @tree: Pointer to the root node of the tree
 * @index: Index of the node to check
 * @size: Size of the tree
 *
 * Return: true if node is present, false otherwise
 */
bool is_node_present(const binary_tree_t *tree, size_t index, size_t size)
{
	if (index >= size)
		return (false);

	if (index == 0)
		return (true);

	size_t parent_index = (index - 1) / 2;

	if (tree->parent && index % 2 == 0)
		return (is_node_present(tree->parent->right, parent_index,
					size));

	else if (tree->parent)
		return (is_node_present(tree->parent->left, parent_index,

					size));
	
	return (false);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + 1 +
			binary_tree_size(tree->right));
}
