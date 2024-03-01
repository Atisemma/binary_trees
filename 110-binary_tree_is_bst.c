#include "binary_trees.h"
#include "limits.h"
/**
 * is_bst_helper - Checks if a binary tree is a valid BST.
 * @tree: POINTS to the root node of the tree to check.
 * @lo: The value of the lesser node
 * @hi: The value of the greater node
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: points to the root node of the tree to check.
 * Return: 1 if tree is a valid BST,0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
