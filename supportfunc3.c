#include "main.h"

/**
 * trim_buff - Removes the '\n' char, and looks for tabulations
 * @str: The buffer
 * @counter: Length of the string
 *
 * Return: The clean buffer
 */
char *trim_buff(char *str, int counter)
{
	int i = 0, tab = 0;
	str[counter - 1] = '\0';
	

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
	str = comments(str);
	return (str);
}