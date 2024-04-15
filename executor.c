#include "shell.h"

void execute_command(char *command)
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        if (access(command, X_OK) == -1)
        {
            fprintf(stderr, "%s: command not found\n", command);
            exit(EXIT_FAILURE);
        }
        execl(command, command, NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }
}
