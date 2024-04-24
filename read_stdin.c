#include "main.h"

/**
 * read_stream - Reads a line from the stream.
 *
 * Return: A pointer to the read line.
 */
char *read_stream(void)
{
	int bufsize = 1024;
	int i = 0;
	char *line = malloc(sizeof(char) * bufsize);

	if (line == NULL)
	{
		fprintf(stderr, "allocation error in read_stream");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		if (fgets(&line[i], bufsize - i, stdin) == NULL)
		{
			free(line);
			exit(EXIT_SUCCESS); /* Assuming EOF should exit */
		}

		char *nl_pos = strchr(&line[i], '\n');
		if (nl_pos != NULL)
		{
			*nl_pos = '\0';
			return (line);
		}

		i += strlen(&line[i]);

		if (i >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}

	return (NULL); /* Never reaches here */
}
