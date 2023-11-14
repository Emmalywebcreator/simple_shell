#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

void execute_command(char *command) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
    } else if (pid == 0) {
        char *args[2];
        args[0] = command;
        args[1] = NULL;
        
        execvp(command, args);
        
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {

        printf("SimpleShell> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the shell.\n");
            break;
        }

        execute_command(input);
    }

    return 0;
}

