#include "main.h"

/**
 * main - entry point
 * Discription:  This is a team project on simple shell
 * Return: (0) always for success
 */
int main(int argc, char **argv)
{
	char *prompt = "(Emmy/Namy/shel)$ ";
	char *input = NULL;
	size_t input_size = 0;
	ssize_t input_read;

	while (true)
	{
		(void)argc; 
		(void)argv;

		_printf("%s", prompt); 

		if (getline(&input, &input_size, stdin) == -1)
		{
			perror("getline failed");
			break;
		}

		input_read = strlen(input);
		if (input_read > 0 && input[input_read -1] == '\n')
		{
			input[input_read -1] = '\0';
		}

		execute_command(input);

		free(input);
	}

	return (EXIT_SUCCESS);
}
