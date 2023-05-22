#include "main.h"

/**
 * is_exit - Built-In inter for exit
 * @str: String to compare
 *
 * Return: int
 */
int is_exit(char *str)
{
	char *cpy = _strdup(str);

	if (strcmp(_strtok(cpy, ' '), "exit") == 0)
	{
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}


/**
 * checkEnv - Built-In inter for env
 * @str: String to compare
 *
 * Return: int
 */
int checkEnv(char *str)
{
	char *cpy = _strdup(str);

	if (_strcmp(_strtok(cpy, ' '), "env") == 0)
	{
		free(cpy);
		printenv();
		return (1);
	}
	free(cpy);
	return (0);
}


/**
 * is_help - Built-In checker for Help
 * @str: String to compare
 *
 * Return: If there's a coincidence or not
 */
int is_help(char *str)
{
	char *cpy = _strdup(str), *name = NULL;

	if (_strcmp(_strtok(cpy, ' '), "help") == 0)
	{
		name = _strtok(NULL, ' ');
		if (name == NULL)
		{
			write(1, "Usage: help [BUILTIN]\nList of Built-Ins\n", 41);
			write(1, "cd\nexit\nsetenv\nunsetenv\nenv\nhelp\n", 34);
			free(cpy);
			return (1);
		}
		else
		{
			while (name != NULL)
			{
				case_assist(name);
				name = _strtok(NULL, ' ');
			}
		}
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}