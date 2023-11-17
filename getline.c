#include "main.h"
/*
 * custome_getline() - Returns a custom getline
 * Return - always 0
 */
int getline_function(void)
{
	char *line;

	while ((line = custom_getline()) != NULL)
	{
		_printf("Read line: %s\n", line);
		free(line);
	}
	return (0);
}
