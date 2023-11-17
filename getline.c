#include "main.h"
/*
 * custome_getline() - Returns a custom getline
 * Return - always 0
 */
int getline_function(void)
{
	char *line_start;

	while ((line_start = custom_getline()) != NULL)
	{
		_printf("Read line: %s\n", line_start);
		free(line_start);
	}
	return (0);
}
