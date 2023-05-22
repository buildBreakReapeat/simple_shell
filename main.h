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
char *str_concat(char *s1, char *s2);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
char *_strtok(char *str, char delim);
char *_strcpy(char *dest, char *src);





#endif