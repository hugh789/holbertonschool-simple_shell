#include "main.h"

/**
 * split_line - split a string from read_line into multiple strings aka tokenize
 * @line: string to be tokenized
 * 
 * Return: pointer that points to the new array
*/
char **split_line(char *line)
{
    int bufsize = 64;
    int i = 0;
    char **tokens = malloc(bufsize * sizeof(char));
    char *token;

    if (!tokens)
    {
        fprint(stderr, "allocation error in split_line: tokens\n");
        exit(EXIT_FAILURE);
    }
    token strtok(line, TOK_DELIM);
    while (token != NULL)
    {
        /* handle comments*/
        if (token[0] == '#')
        {
            break;
        }
        tokens[i] = token;
        i++;
        if (i >= bufsize)
        {
            bufsize += bufsize;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "reallocation error in split_line: token")
                exit (EXIT_FAILURE);
            }
        }
        token = strtok(NULL, TOK_DELIM);
    } 
    tokens[i] = NULL;
    return (tokens);
}
