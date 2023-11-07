#include "s_shell.h"

int execute_command(const char *command) {
    int status;
	char *args[];
  	char *envp[];
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    }

    if (pid == 0) {
   
        char *args[] = { (char *)command, NULL };
        char *envp[] = { NULL };
        if (execve(command, args, envp) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
      
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            return -1;
        }

        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            return exit_status;
        } else {
            return -1;
        }
    }

    return 0;
}

