#include "main.h"

/**
 * exec_command - Execute a command in new process
 * @path_full: Full path to the command executable func
 * @args: Array of arguments for the commands
 * @envp: Array of env vals
 * @path_full: Full path to the executable including the command.
 * @args: Array of strings representing command-line arguments.
 * @envp: Array of strings representing environment variables.
 */
void exec_command(char *path_full, char *args[], char *envp[])
{
	pid_t pid = fork();

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
	}
}

/**
 * execute_direct_command - executes a direct command
 * @command: user input
 * @envp: evn variabe
 * @args: arguments
 * return: nothing
 */
void execute_direct_command(char *command, char *args[], char *envp[])
{
	pid_t pid = fork();

	if (pid == 0)
	{
		execve(command, args, envp);
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
	}
}
/**
 * execute_command_using_path - execute user command considering /bin
 * @command: user input
 * @args: arguments
 * @envp: environment variables
 * Return: nothing
 */
void execute_command_using_path(char *command, char *args[], char *envp[])
{
	char *path = getenv("PATH");
	char *copy_path = strdup(path);
	char *dir_token = strtok(copy_path, ":");

	if (strchr(command, '/'))
	{
		execute_direct_command(command, args, envp);
		return;
	}
	while (dir_token != NULL)
	{
		char *path_full = malloc(_strlen(dir_token) +
				_strlen("/") + _strlen(command) + 1);

		if (path_full == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		snprintf(path_full, _strlen(dir_token) + _strlen("/")
				+ _strlen(command) + 1, "%s/%s", dir_token, command);

		if (access(path_full, X_OK) == 0)
		{
			exec_command(path_full, args, envp);
			free(path_full);
			return;
		}
		free(path_full);
		dir_token = strtok(NULL, ":");
	}
	fprintf(stderr, "Command not found: %s\n", command);
	exit(EXIT_FAILURE);
}
