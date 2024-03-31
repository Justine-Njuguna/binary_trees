#include "binary_trees.h"

/**
 * bst_find_min - Helper function to find the minimum value node in a BST.
 * @root: The root of the BST.
 *
 * Return: The node with the minimum value.
 */
bst_t *bst_find_min(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;

	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 *
 * Return: Ptr to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);
	if (value < root->n) /* Value is in the left subtree */
		root->left = bst_remove(root->left, value);
	else if (value > root->n) /* Value is in the right subtree */
		root->right = bst_remove(root->right, value);
	else /* This is the node to be deleted */
	{
		if (root->left == NULL) /* Node with only > child ! child */
		{
			bst_t *temp = root->right;

			if (temp != NULL)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->right == NULL) /* Node with only left child */
		{
			bst_t *temp = root->left;

			temp->parent = root->parent;
			free(root);
			return (temp);
		}
		bst_t *temp = bst_find_min(root->right);

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

