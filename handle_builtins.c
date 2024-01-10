#include "simple_shell.h"
/**
 * builtins_handle - checks for builtin commands
 * @args: commandline arguments list
 * @argc: no. of command line arguments
 * Return: true if is a builtin and false if otherwise
 **/
bool builtins_handle(char **args, int argc)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		handle_exit(args, argc);
		return (true);
	}
	return (false);
}

/**
 * handle_exit - handles the exit builtin command
 * @args_exit: list of arguments parsed
 * @argc: no. of arguments parsed
 **/
void handle_exit(char **args_exit, int argc)
{
	int status;

	status = EXIT_SUCCESS;

	if (args_exit[1])
		status = _atoi(args_exit[1]);

	free_vector(args_exit, argc);
	exit(status);
}
