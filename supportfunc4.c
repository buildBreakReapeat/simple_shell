#include "main.h"

/**
 * _isdigit - Chekcs only digits in string
 * @str: str
 *
 * Return: if digits or not
 */
int _isdigit(char *str)
{
	int i = 0, flag = 0;

	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			i++;
			continue;
		}
		else
		{
			flag++;
			break;
		}
	}
	return (flag);
}



/**
 * child_fork - Forks a process
 * @child_pid: Process ID of the child process
 * @name: Name of the program
 *
 * Return: The child process ID
 */
int child_fork(pid_t child_pid, char *name)
{
	child_pid = fork();
	if (child_pid == -1)
	{
		perror(name);
		exit(EXIT_FAILURE);
	}
	return (child_pid);
}

/**
 * tokenize - tokenizes string
 * @str: str to tokenize
 * @builtIn: if there's a built-in or not
 *
 * Return: An array of tokenized strings
 */
char **tokenize(char *str, int builtIn)
{
	char *token = NULL, **array = NULL, *test = NULL;
	int size = 0, n = 0;
	struct stat st = {0};

	size = args(str);
	array = malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	token = _strtok(str, ' ');
	while (token != NULL)
	{
		array[n] = _strdup(token);
		token = _strtok(NULL, ' ');
		n++;
	}
	if (builtIn == 0 && array[0][0] != '/')
	{
		test = path(array[0]);
		if (test != NULL)
		{
			free(array[0]);
			array[0] = _strdup(test);
		}
		else
		{
			if ((stat(array[0], &st) == 0) || (isDir(array[0]) == 0))
				;
			else
				perror(array[0]);
		}
		free(test);
	}
	array[n] = NULL;
	return (array);
}

/**
 * _strcpy - src copies to dest 
 * @dest: des string
 * @src: srtc string
 *
 * Return: Returns a copy of the source string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}


/**
 * _strncpy - copy a string
 * @dest: string dest
 * @src: string to cpy
 * @n: bytes
 *
 * Return: copy a string to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, a = 0;

	for (i = 0; i < n; i++)
	{
		if (src[i] == '\0')
			a = 1;
		if (a == 0)
			dest[i] = src[i];
		else
		{
			dest[i] = '\0';
		}
	}

	return (dest);
}

