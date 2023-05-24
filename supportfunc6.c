#include "main.h"
#include <errno.h>
/**
 * _strdup - strdup implementation
 * @str: str to duplicate
 *
 * Return: copy a str
 */
char *_strdup(const char *str)
{
	int i, n = 0;
	char *strcopy;

	if (str == NULL)
		return (NULL);
	do {
		n++;
	} while (str[n - 1]);
	strcopy = malloc(sizeof(char) * n);
	if (strcopy == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
	{
		strcopy[i] = str[i];
	}
	return (strcopy);
}


/**
 * _getline - reads input and store it to address [getline] implementation
 * @lineptr: pointer to line
 * @n: size to read
 * @stream: stream
 * Return: pos
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	int *x = &c;

	if (lineptr == NULL || stream == NULL || n == NULL)
	{
	errno = EINVAL;
	return (-1);
	}

	c = getc(stream);
	if (c == EOF)
		return (-1);
	if (*lineptr == NULL)
	{
	*lineptr = malloc(128);
	if (*lineptr == NULL)
		return (-1);
	*n = 128;
	}

	return (betty_is_annoying(lineptr, n, stream, x));
}

/**
 * path - if a file exists
 * @filename: name of file
 *
 * Return:  absolute path of file or NULL
 */
char *path(char *filename)
{
	char *PATH = _getenv("PATH");
	char *clone = _strdup(PATH), *concat = NULL;
	char *token = NULL, *absolute = NULL;
	struct stat st;

	token = _strtok(clone, ':');
	concat = _strcat("/", filename);
	while (token != NULL)
	{
		absolute = _strcat(token, concat);
		if (stat(absolute, &st) == 0)
		{
			free(PATH);
			free(clone);
			free(concat);
			return (absolute);
		}
		token = _strtok(NULL, ':');
		free(absolute);
	}
	free(PATH);
	free(concat);
	free(clone);
	return (NULL);
}



/**
 * _getenv - get env var using environ
 * @var: name of the variable
 *
 * Return: content of env var or NULL
 */
char *_getenv(const char *var)
{
	char *token, *value, *cpy;
	size_t i = 0;

	if (!var)
		exit(1);
	while (environ[i] != NULL)
	{
		cpy = _strdup(environ[i]);
		token = _strtok(cpy, '=');
		if (_strcmp(var, token) == 0)
		{
			token = _strtok(NULL, '=');
			value = malloc(sizeof(char) * _strlen(token) + 1);
			if (!value)
			{
				free(cpy);
				return (NULL);
			}
			_strcpy(value, token);
			free(cpy);
			break;
		}
		i++;
		free(cpy);
	}
	return (value);
}

/**
 * waitAndFree - Waits and frees things
 * @status: Status of the process
 * @argv: Array to free
 * @dup: Duplicated array to free
 *
 * Return: Returns the status of isatty
 */
void wait_free(int status, char **argv, char *dup)
{
	wait(&status);
	free_array_dup(argv, dup);
}
