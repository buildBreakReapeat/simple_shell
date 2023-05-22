#include "main.h"

/**
 * _isdigit - isdigit implementation
 * @str: str to search
 *
 * Return: If it's only digits or not
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
 * free_array_dup - free array and the duplicated str
 * @array: arrto free
 * @dup: dup string to free
 */
void free_array_dup(char **array, char *dup)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
	free(dup);
}


/**
 * free_and_exit - Frees a buffer and exits the function
 * @buffer: Buffer to free
 */
void free_and_exit(char *buffer)
{
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(0);
}

/*
strncmp implementation
error handlin
check edge cases
delstr
*/ 
