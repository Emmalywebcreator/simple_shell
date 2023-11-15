#include "main.h"
/*
 *execute_command_using_path - This executes using the command without /bin
 *return: Always (0)
 */
void execute_command_using_path(char *command, char *args[], char *envp[])
{
	char *path = getenv("PATH");
	char *copy_path = strdup(path);
	char *dir_token = strtok(copy_path, ":");
	pid_t pid;

	while (dir_token != NULL)
	{
		char *path_full = malloc(strlen(dir_token)
					+ strlen("/") + strlen(command) + 1);

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
				free(path_full);
				free(copy_path);
				return;
			}
		}

		free(path_full);
		dir_token = strtok(NULL, ":");
	}
	/*Free the path here*/
	free(copy_path);
	fprintf(stderr, "Command not found: %s\n", command);
	exit(EXIT_FAILURE);
}
