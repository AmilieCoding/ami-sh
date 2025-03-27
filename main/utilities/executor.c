#include "shell.h"

// -> Actually handling the commands :3
void execute_command(char **args) {
    if (args[0] == NULL) return;

    // -> Error handling :3
    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        perror("exec failed");
        exit(1);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("fork failed");
    }
}
