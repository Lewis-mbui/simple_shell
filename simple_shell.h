#ifndef _SIMPLE_SHELL_H_
#define _SIMPLE_SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char **args_split(char *args, int argc);
bool builtins_handle(char **args, int argc);
int args_count(char *args);
char *_strcpy(char *dest, const char *src);
char *get_PATH(char *name);
int _strcmp(char *str1, char *str2);
bool check_for_file(char *file_name);
char *path_for_file(char *file_name);
char *_strconcat(char *str1, char *str2);
void free_vector(char **vec, int len);
void execute(char **args, char **env);
int _atoi(char *str);
void handle_exit(char **args_exit, int argc);

#endif
