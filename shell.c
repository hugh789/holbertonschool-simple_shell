#include "shell.h"

int main(__attribute((unused)) int argc, __attribute((unused)) char **argv)
{
	char *input, **full_cmd;
	while (1)
	{
		input = readline();
		full_cmd = tokenizer(input);
		if (!full_cmd)
			continue;
		run_cmd (full_cmd);
	}
	return 0;
}
