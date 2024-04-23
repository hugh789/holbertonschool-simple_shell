#include "main.h"

/**
 * execute_args - determine if command is a builtin or a process
 * @args: command and its flags
 *
 * Return: 1 on success, 0 otherwise
 */
int execute_args(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	int (*builtin_func[])(char **) = {
		&own_cd,
		&own_env,
		&own_help,
		&own_exit
	};
	size_t num_builtins = sizeof(builtin_func_list) / sizeof(char *);

	if (args[0] == NULL)
		return (-1); /* empty command was entered */

	/* find if the command is a builtin */
	for (size_t i = 0; i < num_builtins; i++)
	{
		/* if there is a match execute the builtin command */
		if (strcmp(args[0], builtin_func_list[i]) == 0)
			return ((*builtin_func[i])(args));
	}

	/* create a new process */
	return (new_process(args));
}
