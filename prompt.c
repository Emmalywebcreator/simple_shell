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
	char *dup_buf, *delimiter = " ", *token;

	buf = NULL;
	n = 0;

	_printf("Emmy/Namy/shell$ ");
	no_of_bytes_read = getline(&buf, &n, stdin);
	
	if (no_of_bytes_read == -1)
	{
		perror("getline");

		return (-1);
	}

	if (no_of_bytes_read > 0 && buf[no_of_bytes_read - 1] == '\n')
	{
		buf[no_of_bytes_read - 1] = '\0';

		dup_buf = strdup(buf);

		if (dup_buf == NULL)
		{
			perror("strdup");
			return (-1);
		}
		token = strtok(dup_buf, delimiter);

		while (token != NULL)
		{
			_printf("%s\n", token);

			token = strtok(NULL, delimiter);
 		}
		free(dup_buf);

	}
	free(buf);
	return (no_of_bytes_read);
}
