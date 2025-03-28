#include "shell.h"

// -> Actually handling the commands :3
int execute_command(char **args) {
    pid_t pid = fork();
    
    if (pid == 0) {
        // -> If PID == 0 then it is child process, if it fails to run
        // -> It will then print an error message with perror. It then
        // -> Proceeds to exit.
        execvp(args[0], args);
        perror("ami-sh");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // -> Ensure prompt is on a new line (I hope!)
        int status;
        waitpid(pid, &status, 0);
        printf("\n");
    } else {
        // -> Incase forking PID fails :cri:
        perror("ami-sh");
    }

    return 1;
}
