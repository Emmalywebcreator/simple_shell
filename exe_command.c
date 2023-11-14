#include "main.h"

int execute_command(char *input)
{
	char *token, *delim = " ";
	pid_t pid;
	char *input_dup;
	char *args[50]; 
	char *envp[] = { NULL };
	int i;

	input_dup = strdup(input);
	if (input_dup == NULL)
	{
		perror("Memory allocation failed");
		free(input);
		exit(EXIT_FAILURE);
	}

	i = 0;
	token = strtok(input_dup, delim);
	while (token != NULL && i < 49)
	{
		args[i++] = token;
		_printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	args[i] = NULL;

	pid = fork();

	if (pid == 0) 
	{
		execve(args[0], args, envp);
		perror("Command execution failed");
		free(input_dup);
		free(input);
		exit(EXIT_FAILURE);
	}

	else if (pid < 0)
	{
		perror("Forking failed");
		free(input_dup);
		free(input);
	}
	else
	{
		waitpid(pid, NULL, 0);

		free(input_dup);
	}

	return (0);
}

