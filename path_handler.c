#include "main.h"

/**
 * execute_command_using_path - execute user command considering /bin
 * @command: user input
 * @args: arguments
 * @envp: environment variables
 * Return: nothing
 */
void execute_command_using_path(char *command, char *args[], char *envp[])
{
    // If the command contains '/', try executing directly
    if (strchr(command, '/'))
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
            return;
        }
    }

    // If not, prepend '/bin/' to the command and search in PATH directories
    char *path = getenv("PATH");
    char *copy_path = strdup(path);
    char *dir_token = strtok(copy_path, ":");
    pid_t pid;

    while (dir_token != NULL)
    {
        char *path_full = malloc(_strlen(dir_token) + _strlen("/") + _strlen(command) + 1);

        if (path_full == NULL)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        snprintf(path_full, _strlen(dir_token) + _strlen("/") + _strlen(command) + 1, "%s/%s", dir_token, command);
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
                return;
            }
        }

        free(path_full);
        dir_token = strtok(NULL, ":");
    }

    fprintf(stderr, "Command not found: %s\n", command);
    exit(EXIT_FAILURE);
}

