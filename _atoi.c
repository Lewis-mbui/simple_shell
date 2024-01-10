#include "simple_shell.h"
/**
 * _atoi - converts a given string to an integer
 * @str: string to convert
 * Return: converted integer
 **/
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;/* Default positive sign */

	/* Skip leading whitespaces */
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;

	/* Handle the sign */
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	/* Process digits and build the result */
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}
