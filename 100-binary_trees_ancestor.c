#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: Points to the first node.
 * @second: Points to the second node.
 * Return: A pointer to the lowest common multiple ancestor node,
 * or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *moms, *pops;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	moms = first->parent, pops = second->parent;
	if (first == pops || !moms || (!moms->parent && pops))
		return (binary_trees_ancestor(first, pops));
	else if (moms == second || !pops || (!pops->parent && moms))
		return (binary_trees_ancestor(moms, second));
	return (binary_trees_ancestor(moms, pops));
}
