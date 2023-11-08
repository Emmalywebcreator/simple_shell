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
/**
 * _printf - This function prints variable n. or argument
 * like the standard printf function
 * @format: argument to be printed
 * @...: An ellipse of other argument
 * Return: Total character count
 */
int _printf(const char *format, ...)
{
	int chr_count = 0;
	va_list no_input_args;

	if (format == NULL)
		return (-1);
	va_start(no_input_args, format);
	while (*format)
	{
		if (*format != '%')
		{
			chr_count += _write_char(*format);
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == 'c')
			{
				char c = va_arg(no_input_args, int);

				chr_count += _write_char(c);
			}
			else if (*format == 's')
			{
				char *str = va_arg(no_input_args, char*);

				chr_count += _write_string(str);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int number = va_arg(no_input_args, int);

				chr_count += _write_integer(number);
			}
			else if (*format == '%')
			{
				chr_count += _write_percent();
			}
		}
		format++;
	}
	va_end(no_input_args);
	return (chr_count);
}
