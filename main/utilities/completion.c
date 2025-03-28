#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

// -> Generates command suggestions for tab completion
char *command_generator(const char *text, int state) {
    static int index, len;
    char *commands[] = {"exit", "cd", "help", "alias", "export", NULL}; // Add more commands

    if (state == 0) { // Reset on first call
        index = 0;
        len = strlen(text);
    }

    while (commands[index]) {
        if (strncmp(commands[index], text, len) == 0) {
            return strdup(commands[index++]);
        }
        index++;
    }
    return NULL; // No more matches
}

// -> Handles tab completion logic
char **ami_completion(const char *text, int start, int end) {
    (void)start; (void)end; // Unused parameters
    return rl_completion_matches(text, command_generator);
}
