#include "main.h"

/**
 * is_exit - exit cmd
 * @str: str to cmp
 *
 * Return: int
 */
int is_exit(char *str)
{
	char *cpy = _strdup(str);

	if (_strcmp(_strtok(cpy, ' '), "exit") == 0)
	{
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}


/**
 * checkEnv - env cmd
 * @str: str to search
 *
 * Return: int
 */
int checkEnv(char *str)
{
    int i = 0;
	char *cpy = _strdup(str);

	if (_strcmp(_strtok(cpy, ' '), "env") == 0)
	{
		free(cpy);
		while (environ[i])
        {
            write(1, environ[i], _strlen(environ[i]));
            write(1, "\n", 1);
            i++;
        }
		return (1);
	}
	free(cpy);
	return (0);
}


/**
 * is_help - checks for Help
 * @str: str to cmp
 *
 * Return: int
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


/**
 * case_assist - message stdout
 * @name: Name of the Built-In
 */
void case_assist(char *name)
{
	if (_strcmp(name, "cd") == 0)
	{
		write(1, "cd [dir]\nChange the shell working directory.\n", 46);
	}
	else if (_strcmp(name, "exit") == 0)
	{
		write(1, "exit [n]\nExits the shell with a status of N.\n", 46);
	}
	else if (_strcmp(name, "setenv") == 0)
	{
		write(1, "setenv [var] [value]\nSet environment variables.\n", 49);
	}
	else if (_strcmp(name, "unsetenv") == 0)
	{
		write(1, "unsetenv [var]\nUnset environment variables.\n", 45);
	}
	else if (_strcmp(name, "help") == 0)
	{
		write(1, "help [BUILTIN]\nDisplays information for Buitlt-Ins.\n", 53);
	}
	else if (_strcmp(name, "env") == 0)
	{
		write(1, "env\nPrint all environment variables.\n", 38);
	}
	else
	{
		write(1, "Wrong Built-In, use help to list all Built-Ins\n", 48);
	}
}

/**
 * _unsetenv - deletes var name from the environ
 * @name: variable namwe
 *
 * Return: 0 or -1 
 */
int _unsetenv(char *name)
{
	size_t len = 0;
	int i = 0, flag = 0;

	len = _strlen(name);
	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], name, len) == 0)
		{
			while (environ[i] != NULL)
			{
				environ[i] = environ[i + 1];
				i++;
			}
			flag++;
			break;
		}
		i++;
	}
	if (flag > 0)
		return (0);
	return (-1);
}