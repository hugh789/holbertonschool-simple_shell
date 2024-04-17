#include "main.h"
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * path_command - Searches for a command in the system PATH.
 * @command: Command to search for.
 * Returns: Full path of command if found, NULL otherwise.
 */
char *path_command(char *command)
{
    int i = 0;
    char *token = NULL;
    struct stat sb;
    char *cache;
    char *ptr = NULL;

    while (environ[i])
    {
        cache = strdup(environ[i]);
        token = strtok(cache, "=");

        if (strcmp(token, "PATH") == 0)
        {
            token = strtok(NULL, "=");
            token = strtok(token, ":");

            while (token)
            {
                ptr = malloc(strlen(token) + strlen(command) + 2);
                if (ptr == NULL) {
                    perror("Failed to allocate memory");
                    free(cache);
                    return NULL;
                }
                
                ptr[0] = '\0'; 
                assembly_command(token, command, &ptr);

                if (stat(ptr, &sb) == 0) 
                {
                    free(cache);
                    return ptr; 
                }
                
                free(ptr); 
                token = strtok(NULL, ":");
            }
            free(cache);
            break;
        }
        free(cache);
        i++;
    }
    return NULL;
}


