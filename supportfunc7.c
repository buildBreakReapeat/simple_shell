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