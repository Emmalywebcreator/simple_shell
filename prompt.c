#include "main.h"
/**
 * shell_prompt: display a prompt and wait for user input.
 * buf: a buffer to store the user's input.
 * n: the maximum length of the input.
 * Returns the number of characters read or -1 on error.
 */

ssize_t shell_prompt(char *buf, size_t n)
{
	ssize_t no_of_bytes_read;
	buf = NULL;
	n = 0;

	_printf("emmy$ ");
	no_of_bytes_read = getline(&buf, &n, stdin);
	_printf("%s", buf);
	
	if (no_of_bytes_read == -1)
	{
		perror("getline");

		return (-1);
	}

	if (no_of_bytes_read > 0 && buf[no_of_bytes_read - 1] == '\n')
	{
		buf[no_of_bytes_read - 1] = '\0';
	}

	free(buf);
	return (no_of_bytes_read);
}
