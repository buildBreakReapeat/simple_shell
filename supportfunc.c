#include "main.h"

/**
 * is_str - search for a str buff
 * @str: The buffer
 * Return: char || !char
 */
int is_str(char *str)
{
	int idx = 0, result = -1;

	if (str[0] == '#')
		return (result);
	while (str[idx])
	{
		if (str[idx] != 32 && str[idx] != 10 && str[idx] != '\t' && str[idx] != '#')
		{
			result = 0;
			if (str[0] == ' ' && str[1] != ' ')
			{
				str = _strtok(str, ' ');
			}
			break;
		}
		if (str[idx] == '#')
			break;
		idx++;
	}
	return (result);
}

/**
 * is_setenv - checker for setenv and edge cases
 * @str: String to compare
 *
 * Return: If there's a coincidence or not
 */
int is_setenv(char *str)
{
	char *clone = _strdup(str), *name = NULL, *value = NULL;

	if (strcmp(_strtok(clone, ' '), "setenv") == 0)
	{
		name = _strtok(NULL, ' ');
		value = _strtok(NULL, ' ');
		if (name == NULL || value == NULL)
		{
			write(STDERR_FILENO, "Usage: setenv [VARIABLE] [VALUE]\n", 34);
			free(clone);
			return (1);
		}
		_setenv(name, value, 1);
		free(clone);
		return (1);
	}
	free(clone);
	return (0);
}

/**
 * is_unset - checker for setenv and edge cases
 * @str: String to compare
 *
 * Return: If there's a coincidence or not
 */
int is_unset(char *str)
{
	char *clone = _strdup(str), *token = NULL;

	if (strcmp(_strtok(clone, ' '), "unsetenv") == 0)
	{
		token = _strtok(NULL, ' ');
		if (token == NULL)
		{
			write(STDERR_FILENO, "Usage: unsetenv [VARIABLE]\n", 28);
			free(clone);
			return (1);
		}
		if (_unsetenv(token) == -1)
		{
			write(STDERR_FILENO, "can't unset non-existent variable\n", 35);
			free(clone);
			return (1);
		}
		free(clone);
		return (1);
	}
	free(clone);
	return (0);
}