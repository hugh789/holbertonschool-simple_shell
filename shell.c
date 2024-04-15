#include "shell.h"

void run_shell(void)
{
    char *input;
    while (1)
    {
        input = read_input();
        if (!input)
            break;
        execute_command(input);
        free(input);
    }
}
