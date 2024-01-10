#include "simple_shell.h"

/**
 * check_for_file - checks for file existence in the directory
 * @file_name: file to check for
 * Return: true if file is found and false otherwise
 **/

bool check_for_file(char *file_name)
{
	if (access(file_name, F_OK) == 0)
		return (true);
	else
		return (false);
}
