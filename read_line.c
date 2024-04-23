#include "main.h"

/**
 * read_line - Read a line of input from standard input.
 *
 * Return: A pointer to the character array containing the read line.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1) /* if getline fails */
	{
		if (feof(stdin)) /* test for the end of function */
		{
			free(line); /* Avoid memory leaks when ctrl + d */
			exit(EXIT_SUCCESS); /* We received an EOF */
		}
		else
		{
			free(line); /* Avoid memory leaks when getline fails */
			perror("error while reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
