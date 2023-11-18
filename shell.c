#include "main.h"
/**
 * display_prompt - display a prompt for user input
 */
void display_prompt()
{
	char *prompt = "(Emmy/Namy/shel)$ ";

	_printf("%s", prompt);
	fflush(stdout);
}
/**
 * main - entry point
 * Discription:  This is a team project on simple shell
 * @argc: argument count
 * @argv: argument vector
 * Return: (0) always for success
 */
int main(int argc, char **argv)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t input_read;

	if(isatty(0))
	{
		while (true)
		{
			(void)argc;
			(void)argv;

			display_prompt();

			if (getline(&input, &input_size, stdin) == -1)
			{
				perror("getline failed");
				break;
			}

			input_read = _strlen(input);
			if (input_read > 0 && input[input_read - 1] == '\n')
			{
				input[input_read - 1] = '\0';
			}
			
			handle_exit_command(input);
			execute_command(input);

		}


	}
	return (EXIT_SUCCESS);
}
