#include "shell.h"

int handle_builtin(char **args) {
    if (args[0] == NULL) return 0;

        // -> Meow? :3
    if (strcmp(args[0], "meow") == 0){
        printf("Mrrp mrow meow :3\n");
        return 1;
    }

    // -> Exit Command :3
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    }

    // -> CD Command :3 Pretty easy to use :3
    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "cd: expected argument\n");
        } else {
            if (chdir(args[1]) != 0) {
                perror("cd failed");
            }
        }
        return 1;
    }

    return 0;
}
