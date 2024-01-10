#include "simple_shell.h"

/**
 * execute - executes commands
 * @args: command line arguments
 * @env: environment variable
 **/

void execute(char **args, char **env)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error with fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("Error with execution");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
