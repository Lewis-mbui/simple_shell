#include "simple_shell.h"

/**
 * get_PATH - searches the environment list for variable PATH
 * @name: the path variable
 * Return: string associated with path or NULL
 * if path is absent
 **/

char *get_PATH(char *name)
{
	int i = 0;
	char *token;

	while (environ[i] != NULL)
	{
		token = strtok(environ[i], "=");

		if (_strcmp(token, name) == 0)
			return (strtok(NULL, "="));
		i++;
	}
	return (NULL);
}
