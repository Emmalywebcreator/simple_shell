#include "main.h"
/**
 * _strtok - tokenise a string
 * @str: string to be tokenise
 * @delim: delimeter
 * Return: pointer to the next token, or NULL if no more tokens
 */

 char *_strtok(char *str, const char *delim)
{
	char *start;
	static char *current;

	if (str != NULL)
	{
		current = str;
	}
	if (current == NULL || *current == '\0')
	{
		return (NULL);
	}
	while (*current != '\0' && strchr(delim, *current) != NULL)
	{
		current++;
	}

	start = current;
	while (*current != '\0' && strchr(delim, *current) == NULL)
	{
		current++;
	}
	if (*current != '\0')
	{
		*current = '\0';
		current++;
	}
	return (start);
}

