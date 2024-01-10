#include "simple_shell.h"

/**
 * free_vector - frees a vector
 * @vec: vector to be freed
 * @len: number of elements in the vector
 **/

void free_vector(char **vec, int len)
{
	int i;

	for (i = 0; i < len; i++)
		free(vec[i]);
	free(vec);
}
