#include "main.h"

/**
 * trim_buff - Removes the '\t' char, '\n'
 * @str: The buffer
 * @size: size string
 *
 * Return: trimmed buffer
 */
char *trim_buff(char *str, int size)
{
	int i = 0, tab = 0;
	str[size - 1] = '\0';
	

	while (str[i])
	{
		if (str[i] == '\t')
		{
			tab++;
		}
		i++;
	}
	i = 0;
	if (tab > 0)
	{
		while (str[i])
		{
			if (str[i] == '\t')
			{
				str[i] = ' ';
			}
			i++;
		}
	}
	str = trim_hash(str);
	return (str);
}


/**
 * trim_hash - comments
 * @str: str to serach
 *
 * Return: clean str if comments, if not same str
 */
char *trim_hash(char *str)
{
	int i = 0, j = 0, hash = 0, flag = 0;

	while (str[j])
	{
		if (str[j] == ' ' && str[j + 1] == '#')
		{
			hash++;
			break;
		}
		j++;
	}
	if (hash == 0)
		return (str);
	while (str[i])
	{
		if (flag == 1)
		{
			str[i] = ' ';
			i++;
			continue;
		}
		if (str[i] == ' ' && str[i + 1] == '#')
		{
			flag++;
			i++;
			continue;
		}
		i++;
	}
	return (str);
}


/**
 * itsExecutable - Checks if path i executable
 * @path: path of the file
 *
 * Return: If executable or not
 */
int itsExecutable(char *path)
{
	if (isDir(path) == 0)
	{
		if (path[0] == '/')
			perror(path);
		else
			perror(path);
		return (1);
	}
	if (access(path, X_OK))
		return (2);
	else
		return (0);
}



/**
 * isDir - Checks if the path is a directory
 * @path: path of the file
 *
 * Return: If dir or not
 */
int isDir(const char *path)
{
	struct stat st = {0};

	stat(path, &st);
	return (S_ISREG(st.st_mode));
}


/**
 * getReturnValue - Get exit value
 * @str: String to traverse
 *
 * Return: The exit value
 */
int getReturnValue(char *str)
{
	char *cpy = _strdup(str), *token;
	int exitValue = 0;

	token = _strtok(cpy, ' ');
	token = _strtok(NULL, ' ');
	if (token == NULL)
	{
		free(cpy);
		return (0);
	}
	if (_isdigit(token) == 0)
		exitValue = _atoi(token);
	else
	{
		free(cpy);
		write(STDERR_FILENO, "exit: Illegal number\n", 22);
		return (-1);
	}
	free(cpy);
	if (exitValue < 0)
	{
		write(STDERR_FILENO, "exit: Illegal number\n", 22);
		exitValue = (-1);
	}
	return (exitValue);
}