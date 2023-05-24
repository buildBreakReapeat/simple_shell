#include "main.h"


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
* _strncmp - strncp implementation
* @str1:string 1
* @str2: string 2
* @n: size
* Return: int
*/
int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n && *str1 && (*str1 == *str2))
	{
	str1++;
	str2++;
	n--;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return ((*(unsigned char *)str1 - *(unsigned char *)str2));
	}
}

/**
 * _itoa - converts n to char in str
 * @n: num
 * @s: str
*/
void _itoa(int n, char s[])
{
	int i, sign;

	sign = n;
	if (sign < 0)
		n = -n;
	i = 0;
	do {
	s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	_reverse(s);
}

/**
 * _reverse - converts n to char in str
 * @s: str
*/
void _reverse(char s[])
{
	int i, j;
	char c;

	for (i = 0, j = _strlen(s) - 1; i < j; i++, j--)
	{
	c = s[i];
	s[i] = s[j];
	s[j] = c;
	}
}
