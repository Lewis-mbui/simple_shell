#include "simple_shell.h"
/**
 * main - the primary function to the shell program
 * @ac: number of command line arguments
 * @av: list of command line arguments
 * @env: list of environment variables and values
 * Return: always 0
 **/
int main(int ac, char **av, char **environ)
{
	char *cmd = NULL, *cmd_cpy = NULL;
	size_t n;
	bool pipe_source = false;

	av = NULL;
	ac = 0;

	while (1 && !pipe_source)
	{
		if (isatty(STDIN_FILENO) == 0)
			pipe_source = true;
		write(1, "#Lewis' Shell$ ", 15);
		if (getline(&cmd, &n, stdin) == -1)
		{
			perror("Error with getline");
			free(cmd);
			exit(EXIT_FAILURE);
		}
		cmd_cpy = _strcpy(cmd_cpy, cmd);
		ac = args_count(cmd);
		av = args_split(cmd_cpy, ac);

		if (av == NULL)
			continue;

		execute(av, environ);

		free_vector(av, ac);
	}
	free(cmd);
	return (0);
}
