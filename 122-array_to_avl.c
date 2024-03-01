#include "binary_trees.h"
/**
 * array_to_avl - Function that builds an AVL tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: array size
 * Return: pointer to the root node of the created AVL, or NULL upon failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t a, j;

	if (array == NULL)
		return (NULL);

	for (a = 0; a < size; a++)
	{
		for (j = 0; j < a; j++)
		{
			if (array[j] == array[a])
				break;
		}
		if (j == a)
		{
			if (avl_insert(&tree, array[a]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
