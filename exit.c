#include "main.h"
/**
 * handle_exit_command - exits the shell
 * @command: input to exit the shell
 *
 */
void handle_exit_command(char *command)
{
	if (_strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
}

