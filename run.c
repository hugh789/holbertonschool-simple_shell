#include "shell.h"
int run_cmd(char **full_cmd)
{
    pid_t child;
    int status;
    char *path;
    path = handlepath(full_cmd[0]);
    child = fork();
    if (child == 0)
    {
        if (execve(path, full_cmd, NULL) == -1)
        {
            free(path);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        free(path);
    }
    return (WEXITSTATUS(status));
}
