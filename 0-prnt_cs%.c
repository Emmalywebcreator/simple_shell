#include <stdio.h>
#include "main.h"

/**
 * _print_regular - helper function to print characters that are not '%'
 * @chr_count: Pointer to the character count
 * @format: Current position in the format string
 * Return: void
 */

static void _print_regular(int *chr_count, const char **format)
{
	*chr_count += _write_char(**format);
	(*format)++;
}
/**
 * _print_format - Helper function to handle the format specifiers
 * @chr_count: Pointer to the character count
 * @format: Current position in the format string
 * @no_args: Argument list for va_arg
 * Return: void
 */

static void _print_format(int *chr_count, const char **format, va_list no_args)
{
	(*format)++;
	if (**format == '\0')
		return;

	if (**format == 'c')
	{
		char c = va_arg(no_args, int);
		*chr_count += _write_char(c);
	}
	else if (**format == 's')
	{
		char *str = va_arg(no_args, char*);
		*chr_count += _write_string(str);
	}
	else if (**format == 'd' || **format == 'i')
	{
		int number = va_arg(no_args, int);
		*chr_count += _write_integer(number);
	}
	else if (**format == '%')
	{
		*chr_count += _write_percent();
	}
	(*format)++;
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
	va_list no_args;

	if (format == NULL)
		return (-1);

	va_start(no_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_print_regular(&chr_count, &format);
		}
		else
		{
			_print_format(&chr_count, &format, no_args);
		}
	}

	va_end(no_args);
	return (chr_count);
}
