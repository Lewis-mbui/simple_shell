#include "simple_shell.h"

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */

char *_strcpy(char *dest, const char *src)
{
	if (src == NULL)
		return (NULL);
	size_t length = 0;

	/* Calculate the length of the source string*/
	while (src[length] != '\0')
	{
		length++;
	}
	/* Allocate memory for the destination string */
	dest = (char *)malloc((length + 1) * sizeof(char));

	if (dest == NULL)
	{
		/* Handle memory allocation failure */
		perror("Error with memory allocation");
		exit(-1);
	}
	/* Copy the source string to the destination */
	for (size_t i = 0; i <= length; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
