#include "simple_shell.h"

/**
 * args_count - counts the no. of arguments in commandline
 * @args: arguments
 * Return: the no. of arguments
 **/

int args_count(char *args)
{
	char *token = NULL;
	int argc = 0;

	token = strtok(args, " \n");

	while (token != NULL)
	{
		token = strtok(NULL, " \n");
		argc++;
	}
	return (argc);
}
