#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#define MAX_LINE 1024
#define MAX_ALIASES 100

// -> Structure to store alias mappings
typedef struct {
    char name[50];
    char value[200]; 
} Alias;

// -> Storing defined aliases! :3
Alias aliases[MAX_ALIASES];
int alias_count = 0;

// -> Function to add an alias to the alias list
void add_alias(const char *name, const char *value) {
    if (alias_count < MAX_ALIASES) {
        strcpy(aliases[alias_count].name, name);
        strcpy(aliases[alias_count].value, value);
        alias_count++;
    }
}

// -> Function to replace command arguments with the alias (if it's found ofc :3)
void replace_aliases(char **args) {
    for (int i = 0; i < alias_count; i++) {
        if (strcmp(args[0], aliases[i].name) == 0) {
            args[0] = aliases[i].value;
            break;
        }
    }
}

// -> Function to load configuration from ~/.ami-shrc
void load_config() {
    char path[256];
    snprintf(path, sizeof(path), "%s/.ami-shrc", getenv("HOME"));

    FILE *file = fopen(path, "r");
    if (!file) return;

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || isspace(line[0])) continue;
        line[strcspn(line, "\n")] = 0;

        // -> Handle alias definitions
        if (strncmp(line, "alias ", 6) == 0) {
            char *name = strtok(line + 6, "=");
            char *value = strtok(NULL, "\"");
            if (name && value) add_alias(name, value);
        }
        // -> Handle environment variable exports :3
        else if (strncmp(line, "export ", 7) == 0) {
            char *var = line + 7;
            char *equal = strchr(var, '=');
            if (equal) {
                *equal = '\0'; 
                setenv(var, equal + 1, 1); 
            }
        }
    }
    fclose(file); 
}