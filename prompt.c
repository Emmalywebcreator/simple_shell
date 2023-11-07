#include "s_shell.h"

/**
 * shell_prompt: display a prompt and wait for user input.
 * buf: a buffer to store the user's input.
 * n: the maximum length of the input.
 * Returns the number of characters read or -1 on error.
 */

ssize_t shell_prompt(char *buf, size_t n)
{
	ssize_t no_of_bytes_read;

	our_print("emmy$ ");	
	no_of_bytes_read = getline(&buf, &n, stdin);
	
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
