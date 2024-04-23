#include "main.h"

/**
 * main - function that checks if our shell is called
 * Program calls shell_interactive (displays,reads input,executes & repeats)
 * Return: 0 on success
 */
int main(void)
{
	/* determines if file descriptor is associated with a terminal */
	if (isatty(STDIN_FILENO) == 1)
	{
		shell_interactive();
	}
	else
	{
		shell_no_interactive();
	}
	return (0);
}
