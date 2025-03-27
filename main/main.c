#include "shell.h"
#include <readline/readline.h>
#include <readline/history.h>


// -> Main thing, duh :3
int main() {
    load_config();
    shell_loop();
    return 0;
}

// -> Actual shell loop which initialises the shell.
void shell_loop() {
    char *line = NULL;
    size_t len = 0;
    char **args;

    while (1) {
        printf("%s ", getenv("PROMPT") ? getenv("PROMPT") : "ami-sh $");
    
        char *line = readline(NULL);
        char **args = parse_input(line);
        
        // -> Replacing aliases before running! **IMPORTANT!!!**
        replace_aliases(args);
    
        if (!handle_builtin(args)) {
            execute_command(args);
        }
    
        free(line);
    }
}    