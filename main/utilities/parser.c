#include "shell.h"

// -> Parse the users input :)
// -> Splits user input into different strings for tokenizing :3
char **parse_input(char *line) {
    static char *args[MAX_ARGS];
    int i = 0;

    args[i] = strtok(line, " \n");
    while (args[i] != NULL && i < MAX_ARGS - 1) {
        args[++i] = strtok(NULL, " \n");
    }

    return args;
}
