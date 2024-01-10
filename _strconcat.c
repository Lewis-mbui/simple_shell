#include "simple_shell.h"
/**
 * _strconcat - joins two strings
 * @str1: first string
 * @str2: second string
 * Return: the combined form of str1 and str2
 **/
char *_strconcat(char *str1, char *str2)
{
	size_t len1, len2, i;
	char *result = NULL;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	/* Calculate the length of the concatenated string */
	len1 = 0;

	len2 = 0;

	while (str1[len1] != '\0')
		len1++;

	while (str2[len2] != '\0')
		len2++;
	/* Allocate memory for the concatenated string */
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));

	if (result == NULL)
	{
		/* Handle memory allocation failure */
		perror("Error with memory allocation");
		exit(-1);
	}
	/* Copy the first string to the result */

	for (i = 0; i < len1; i++)
		result[i] = str1[i];
	/* Concatenate the second string to the result */
	for (i = 0; i < len2; i++)
		result[len1 + i] = str2[i];
	/* Null-terminate the result*/
	result[len1 + len2] = '\0';

	return (result);
}
