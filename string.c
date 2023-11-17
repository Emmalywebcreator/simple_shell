#include <stdio.h>
#include <stdlib.h>

/**
 * _strlen - Thid function returns the length of a string
 *
 * @s: string to be returnen
 * Return: length of the string
 */

int _strlen(const char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * _strcat - concatenate two strings
 *
 * @dest: Destination string
 * @src: source string
 * Return: destination string
 */
char *_strcat(char *dest, char *src)
{
	int s1;
	int s2;

	s1 = 0;
	while (dest[s1] != '\0')
	{
		s1++;
	}
	s2 = 0;
	while (src[s2] != '\0')
	{
		dest[s1] = src[s2];
		s1++;
		s2++;
	}
	dest[s1] = '\0';
	return (dest);
}

/**
 * _strcmp - Compares strings values
 * @s1: first string
 * @s2: second string
 * Return: 0 for success
 */
int _strcmp(char *s1, char *s2)
{
	int a = 0;

	while (s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] != s2[a])
		{
			return (s1[a] - s2[a]);
		}
		a++;
	}
	return (0);
}
/**
 * _strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, const char *src)
{
	int n = 0;
	int m;

	while (*(src + n) != '\0')
	{
		n++;
	}
	for (m = 0; m < n; m++)
	{
		dest[m] = src[m];
	}
	dest[n] = '\0';
	return (dest);
}

/**
 * _strdup - duplicate aa string
 * @str: string to be duplicate
 * Return: duplicate
 */

char *_strdup(const char *str)
{
	size_t length;
	char *dup;

	if (str == NULL)
	{
		return (NULL);
	}

	length = _strlen(str);

	dup = malloc(length + 1);
	if (dup == NULL)
	{
		return (NULL);
	}

	_strcpy(dup, str);

	return (dup);
}

