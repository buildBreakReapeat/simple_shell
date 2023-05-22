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

