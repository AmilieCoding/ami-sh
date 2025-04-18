#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_ARGS 10

void load_config();
void shell_loop();
char **parse_input(char *line);
int execute_command(char **args);
int handle_builtin(char **args);
void replace_aliases(char **args);

void free_arguments(char **args);

char **ami_completion(const char *text, int start, int end);

#endif
