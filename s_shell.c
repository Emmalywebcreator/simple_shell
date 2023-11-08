#include "s_shell.h"
#include "main.h"

/**
 * main - entry point
 * Discription:  This is a team project on simple shell
 * Return: (0) always for success
 */
int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read;

	while (true)
	{
		read = shell_prompt(input, input_size);
		if (read == -1)
		{
			break;
		}

		if (read > 0) 
		{
			input[read - 1] = '\0';

			if (execute_command(input) == -1) 
			{

                		_printf("Command not found\n");
			}
        	}

	}

	return (0);
}
