#include "main.h"
/**
 * execute_command_using_path - execute user command without /bin
 * @command: user input
 * @args: argument
 * @envp: environ
 * Return: nothig
 */
void execute_command_using_path(char *command, char *args[], char *envp[])
{
	char *path = getenv("PATH");
	char *copy_path = strdup(path);
	char *dir_token = strtok(copy_path, ":");
	pid_t pid;

	while (dir_token != NULL)
	{
		char *path_full = malloc(_strlen(dir_token)
					+ _strlen("/") + _strlen(command) + 1);

		sprintf(path_full, "%s/%s", dir_token, command);
		if (access(path_full, X_OK) == 0)
		{
			pid = fork();

			if (pid == 0)
			{
				execve(path_full, args, envp);
				perror("Command execution failed");
				exit(EXIT_FAILURE);
			}
			else if (pid < 0)
			{
				perror("Fork failed");
				exit(EXIT_FAILURE);
			}
			else
			{
				waitpid(pid, NULL, 0);
				return;
			}
		}
		free(path_full);
		dir_token = strtok(NULL, ":");
	}
	fprintf(stderr, "Command not found: %s\n", command);
	exit(EXIT_FAILURE);
}
