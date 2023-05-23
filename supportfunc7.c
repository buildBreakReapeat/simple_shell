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

/**
* _strncmp - strncmp implementation
* @str1:string 1
* @str2: string 2
* @n: size
*/ 
int _strncmp(const char *s1, const char *s2, size_t n)
{
    while (n && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
        n--;
    }
    if (n == 0) {
        return 0;
    } else {
        return (*(unsigned char *)s1 - *(unsigned char *)s2);
    }
}

