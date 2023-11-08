#include "shell.h"

int execute_command(const char *command)
{
	int status;
	pid_t pid = fork();
	char **args, *envp[] = { NULL };

	if (pid == -1) 
	{
		perror("fork");
		return -1;
	}


	if (pid == 0) 
	{
		args = (char **)malloc(2 * sizeof(char *));
		if (args == NULL)
		{
			perror("malloc");
			_exit(EXIT_FAILURE);
		}

		args[0] = (char *)command;
		args[1] = NULL;

		if (execve(command, args, envp) == -1) 
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
		free(args);
		_exit(EXIT_SUCCESS);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return -1;
		}
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);
			return exit_status;
		}
		else
		{
			return -1;
		}
	}

	return 0;
}

