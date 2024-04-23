#include "main.h"

/**
 * shell_interactive - prompts for user input
 * reads, processes commands and repeats until exit/error
 * Return: void
 */
void shell_interactive(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		printf("simple_prompts$"); /* print prompt symbol */
		line = read_line(); /* read line from stdin*/
		args = split_line(line); /* tokenize line*/
		status = execute_args(args);
		/* avoid memory leaks */
		free(line);
		free(args);
		/* exit status */
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
