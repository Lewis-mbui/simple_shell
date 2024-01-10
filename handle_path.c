#include "simple_shell.h"
/**
 * path_for_file - Searches for the absolute path of executable
 * @file_name: executable filename
 * Return: absolute path for the executable
 **/
char *path_for_file(char *file_name)
{
	int i = 0, argc = 0;
	char *path_val = NULL, *path_val_cpy = NULL, *token = NULL;
	char *fp1 = NULL, *fp2 = NULL;
	char **argv = NULL;

	path_val = get_PATH("PATH");
	path_val_cpy = _strcpy(NULL, path_val);

	token = strtok(path_val, ":");
	while (token != NULL)
	{
		token = strtok(NULL, ":");
		argc++;
	}
	argv = malloc(sizeof(char *) * (argc + 1));
	token = strtok(path_val_cpy, ":");

	while (token != NULL)
	{
		argv[i] = _strcpy(NULL, token);
		token = strtok(NULL, ":");
		i++;
	}
	argv[i] = NULL;
	for (i = 0; i < argc; i++)
	{
		fp1 = _strconcat(argv[i], "/");
		fp2 = _strconcat(fp1, file_name);
		if (check_for_file(fp2))
		{
			free_vector(argv, argc);
			free(fp1);
			return (fp2);
		}
		free(fp1);
		free(fp2);
	}
	free_vector(argv, argc);
	return (NULL);
}
