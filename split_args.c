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
	char *full_path = NULL;

	argv = malloc(sizeof(char *) * (argc + 1));
	token = strtok(args, " \n");
	for (i = 0; token != NULL; i++)
	{
		argv[i] = _strcpy(NULL, token);
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;
	if (!check_for_file(argv[0]))
	{
		full_path = path_for_file(argv[0]);

		if (full_path == NULL)
		{
			perror("Error with accessing file");
			return (NULL);
		}
		else
		{
			free(argv[0]);
			argv[0] = full_path;
		}
	}
	return (argv);
}
