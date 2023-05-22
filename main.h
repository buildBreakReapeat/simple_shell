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

void printenv(void);
int is_str(char *str);
char *path(char *filename);
int _setenv(char *name, char *value, int overwrite);
int is_unset(char *str);
int is_setenv(char *str);
int is_help(char *str);
int _unsetenv(char *name);
void ctrl_c_handler(int signum);
int _atoi(char *s);
int is_dir(char *str);
#endif