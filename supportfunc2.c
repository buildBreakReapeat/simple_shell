#include "main.h"
/**
 * _setenv - changes or adds an environment variable
 * @name: variable name
 * @value: variable value
 * @overwrite: if func should overwrite or not
 *
 * Return: 0 or -1 
 */
int _setenv(char *name, char *value, int overwrite)
{
	int i = 0;
	size_t len;

	len = _strlen(name);
	while (environ[i] != NULL)
	{
		if ((strncmp(environ[i], name, len) == 0) && overwrite != 0)
		{
			if (overwrite == 2)
			{
				free(environ[i]);
			}
			environ[i] = create_variable(name, value);
			if (!environ[i])
				return (-1);
			return (0);
		}
		i++;
	}
	environ[i] = create_variable(name, value);
	if (!environ[i])
		return (-1);
	environ[i + 1] = NULL;
	return (0);
}



/**
 * ctrl_c_handler - handler for ^C
 * @signum: Signal number
 */
void ctrl_c_handler(__attribute__((unused))int sigum)
{
	write(STDOUT_FILENO, "\n$ ", 4);
}

/**
 * create_variable - creates a variable
 * @name: variable namw
 * @value: variable val
 *
 * Return: new val
 */
char *create_variable(char *name, char *value)
{
	char *var = NULL, *concat = NULL;

	concat = _strcat(name, "=");
	if (!concat)
		return (NULL);
	var = _strcat(concat, value);
	if (!var)
		return (NULL);
	free(concat);
	return (var);
}

/**
 * args - Counts arguments of a function
 * @str: String to traverse
 *
 * Return: count arguments
 */
int args(char *str)
{
	int i = 1, counter = 0;

	if (str[0] != ' ')
		counter++;
	if (str[0] == ' ' && (str[1] != ' ' && str[1] != '\0'))
		counter++;
	while (str[i])
	{
		if (str[i] == ' ' && (str[i + 1] != ' ' && str[i + 1] != '\0'))
			counter++;
		i++;
	}
	return (counter);
}

/**
 * signal_isatty - signals check and isatty function
 */
void signal_isatty(void)
{
	signal(SIGINT, ctrl_c_handler);
	if ((isatty(STDIN_FILENO) == 1))
		write(STDOUT_FILENO, "$ ", 3);
}