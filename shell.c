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
		if (input == NULL)
		{
			input = (char *)malloc(input_size);
			if(input == NULL)
			{
				break;
			}
		}
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
		free(input);
		input = NULL;
	}

	return (0);
}
