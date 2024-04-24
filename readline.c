#include "shell.h"

char *readline(void)
{
    size_t len = 0;
    char *buffer = NULL;
    printf("$ ");
    getline(&buffer, &len, stdin);
    return buffer;
}
