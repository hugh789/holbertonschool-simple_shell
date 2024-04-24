#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <sys/stat.h>

char *readline(void);
char **tokenizer(char *input);
char *handlepath(char *cmd);
int run_cmd(char **full_cmd);
