#include "shell.h"

char *read_input(void)
{
    char *input = malloc(BUFFER_SIZE);
    if (!input)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    printf("$ ");
    if (!fgets(input, BUFFER_SIZE, stdin))
    {
        free(input);
        return NULL;
    }
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline
    return input;
}
