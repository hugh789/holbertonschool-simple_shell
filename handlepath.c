#include "shell.h"
char *handlepath(char *cmd)
{
    struct stat buffer;
    char *path, *path_cmd;
    int i;
    for (i = 0; cmd[i]; i++)
    {
        if (cmd[i] == '/')
        {
            if (stat(cmd, &buffer) == 0)

            {
                return (cmd);
            }
            return NULL;
        }
    }
    path = "/bin";
    path_cmd = malloc(strlen(path) + strlen(cmd) + 2);
    if (path_cmd == NULL)

    {
        return NULL;
        
    }
    else
    {
        snprintf(path_cmd, strlen(path) + strlen(cmd) + 2, "%s/%s", path, cmd);
        if (stat(path_cmd, &buffer) == 0)
        {
          return path_cmd;  
        }
        
    }
   return NULL; 
}
