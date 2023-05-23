#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/types.h>
extern char **environ;

/**
 * struct list - list
 * @str: str
 * @next: next
 */

typedef struct list
{
	char *str;
	struct list *next;
} list_t;

char *_strdup(const char *str);
char *_strcat(char *str1, char *str2);
int _strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
char *_strtok(char *str, char delim);
char *_strcpy(char *dest, char *src);
char *_getenv(const char *name);
void signal_isatty(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int is_str(char *str);
int _atoi(char *s);
int is_setenv(char *str);
char *path(char *filename);
void ctrl_c_handler(int signum);
int is_help(char *str);
int is_unset(char *str);
int _setenv(char *name, char *value, int overwrite);
int args(char *str);
int _unsetenv(char *name);
char *_strncpy(char *dest, char *src, int n);
void wait_free(int status, char **argv, char *dup);
int _isdigit(char *str);
int is_exit(char *str);
char *create_variable(char *name, char *value);
char *trim_hash(char *str);
int cd_handler(char *str);
char *trim_buff(char *str, int counter);
int is_env(char *str);
void case_assist(char *name);
int getReturnValue(char *str);
char **tokenize(char *str, int builtIn);
int isDir(const char *fileName);
int itsExecutable(char *str);
int child_fork(pid_t child_pid, char *name);
void free_array_dup(char **array, char *dup);
void free_and_exit(char *str);
int _checkBuiltIn(char *str);
#endif
