#include "simple_shell.h"

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 0 if they are same
 * -1 if they are different
 **/
int _strcmp(char *str1, char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return (-1);
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	/* If the loop terminated because characters were different, return -1 */
	if (*str1 != *str2)
	{
		return (-1);
	}
	return (0);
}
