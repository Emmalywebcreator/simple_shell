#include "main.h"

#define BUFFER_SIZE 1024
/*
 * custom_getline - Function defining custom function
 * Return - Always returns (0)
 */
char *custom_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static size_t index = 0;
	static size_t size = 0;
	char *line_start = NULL;
	size_t lineSize = 0;
	int c;

	if (index >= size)
	{
		size = read(0, buffer, BUFFER_SIZE);
		if (size <= 0)
		{
			return NULL;
		}
		index = 0;
	}
	while (index < size)
	{
		c = buffer[index++];
		if (c == '\n')
		{
			break;
		}
		line_start = realloc(line_start, lineSize + 1);
		if(line_start == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		line_start[lineSize++] = (char)c;
	}
	line_start = realloc(line_start, lineSize + 1);
	if (line_start == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	line_start[lineSize] = '\0';
	return line_start;
}
