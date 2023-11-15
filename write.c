#include <stdio.h>
#include "main.h"
/**
 * _write_char - Writes a character to stdout.
 * @c: The character to be written.
 * Return: The number of characters written.
 */
int _write_char(char c)
{
	return (write(1, &c, 1));
}
/**
 * _write_string - Writes a string to stdout.
 * @str: The string to be written.
 * Return: The number of characters written.
 */
int _write_string(const char *str)
{
	int str_len = 0;

	while (str[str_len] != '\0')
		str_len++;
	return (write(1, str, str_len));
}
/**
 * _write_percent - Writes a % character to stdout.
 * Return: The number of characters written.
 */
int _write_percent(void)
{
	return (write(1, "%", 1));
}
/**
 * _write_integer - Writes an interger to stdout
 * @n: The integer to be written
 * Return: The number of characters written to buffer
 */
int _write_integer(int n)
{
	char buffer[32];
	int length = snprintf(buffer, sizeof(buffer), "%d", n);

	return (write(1, buffer, length));
}
