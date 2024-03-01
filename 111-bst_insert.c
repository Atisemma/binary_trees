#include "binary_trees.h"
/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *neww;

	if (tree != NULL)
	{
		curr = *tree;

		if (curr == NULL)
		{
			neww = binary_tree_node(curr, value);
			if (neww == NULL)
				return (NULL);
			return (*tree = neww);
		}

		if (value < curr->n) /* insert in left subtree */
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));

			neww = binary_tree_node(curr, value);
			if (neww == NULL)
				return (NULL);
			return (curr->left = neww);
		}
		if (value > curr->n) /* insert in right subtree */
		{
			if (curr->right != NULL)
				return (bst_insert(&curr->right, value));

			neww = binary_tree_node(curr, value);
			if (neww == NULL)
				return (NULL);
			return (curr->right = neww);
		}
	}
	return (NULL);
}
