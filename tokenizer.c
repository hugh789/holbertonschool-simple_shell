#include "shell.h"

char **tokenizer(char *input)
{
    char *token, *tmp = NULL, **cmd_list = NULL;
    int counter = 0, i = 0;
    if (input == NULL)
        return NULL;
    tmp = strdup(input);
    token = strtok(tmp, " \t\n");
    if (token == NULL)
        return NULL;
    while (token)
    {
        counter++;
        token = strtok(NULL, " \t\n");
    }
    free(tmp);
    cmd_list = malloc(sizeof(char *) * (counter + 1));
    if (cmd_list == NULL)
    {
        free(input);
        return NULL;
    }
    token = strtok (input, " \t\n");
    while (token)
    {
        cmd_list [i] = strdup (token);
        token = strtok(NULL, " \t\n");
        i++;
    }
    free (input);
    cmd_list [i] = NULL;
    return cmd_list;
}
