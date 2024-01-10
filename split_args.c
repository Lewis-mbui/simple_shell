#include "simple_shell.h"
/**
 * args_split - splits command line arguments
 * @args: command line argumetns
 * @argc: number of command line argumets
 * Return: a list of the command line arguments
 **/

char **args_split(char *args, int argc)
{
	int i;
	char **argv = NULL;
	char *token = NULL;

	argv = malloc(sizeof(char *) * (argc + 1));
	token = strtok(args, " \n");

	for (i = 0; token != NULL; i++)
	{
		argv[i] = _strcpy(NULL, token);
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;

	return (argv);
}
