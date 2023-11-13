#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_ARGS 64
#define MAX_COMMAND_LENGTH 140

void show_prompt(void);
void execute_prompt(const char *cmd, char *argv);
void read_cmd(char *cmd, size_t size);
void print_failure(char arg[], char argv[]);
extern char **environ;
void env(void);

#endif
