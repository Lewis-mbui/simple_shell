#include "simple_shell.h"
/**
 * main - the primary function to the shell program
 * @ac: number of command line arguments
 * @av: list of command line arguments
 * @env: list of environment variables and values
 * Return: always 0
 **/
int main(int ac, char **av, char **env)
{
	char *cmd = NULL, *cmd_cpy = NULL, *full_path;
	size_t n;
	bool pipe_source = false;
	int argc, status;
	char **argv = NULL;
	pid_t child_pid;

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
		argc = args_count(cmd);
		argv = args_split(cmd_cpy, argc);

		if (!check_for_file(argv[0]))
		{
			full_path = path_for_file(argv[0]);
			if (full_path == NULL)
			{
				perror("Error with accessing file");
				continue;
			}
			else
			{
				free(argv[0]);
				argv[0] = full_path;
			}
		}
		execute(argv, env);
	}
	return (0);
}
