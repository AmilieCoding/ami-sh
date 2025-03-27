#include "shell.h"

// -> Main thing, duh :3
int main() {
    shell_loop();
    return 0;
}

// -> Actual shell loop which initialises the shell.
void shell_loop() {
    char *line = NULL;
    size_t len = 0;
    char **args;

    while (1) {
        printf("ami-sh $ ");
        getline(&line, &len, stdin);

        args = parse_input(line);
        if (!handle_builtin(args)) {
            execute_command(args);
        }
    }

    free(line);
}
