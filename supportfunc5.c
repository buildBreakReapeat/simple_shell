#include "main.h"

/**
 * _strcat - strcat
 * @str1: first str
 * @str2: second str
 *
 * Return: returns the concat str
 */
char *_strcat(char *str1, char *str2)
{
	int i = 0, j = 0, n = 0;
	char *str;

	if (str1 == NULL)
		str1 = "";
	if (str2 == NULL)
		str2 = "";
	do {
		i++;
	} while (str1[i - 1]);
	do {
		j++;
	} while (str2[j - 1]);
	str = malloc(sizeof(char) * (i + j - 1));
	if (str == NULL)
		return (NULL);

	for (n = 0; n < i; n++)
		str[n] = str1[n];
	for (n = 0; n < j; n++)
		str[n + i - 1] = str2[n];
	return (str);
}

/**
 * _atoi - atoi
 * @str: str
 *
 * Return: int
 */
int _atoi(char *str)
{
	char c;
	unsigned int i, n = 0, j = _strlen(str) - 1, null = -1;
	int flag = 0, sign = 1;

	for (i = 0; i <= j; i++)
	{
		c = str[i];
		if (c == '-')
			sign *= -1;
		if (c >= 48 && c <= 57)
		{
			n = n * 10 + (c - '0');
			flag = 1;
		}
		if (flag == 1)
		{
			if (!(c >= 48 && c <= 57))
				break;
		}
	}
	if (sign == -1)
	{
		n *= -1;
	}
	if (j == null)
		return (0);
	return (n);
}

/**
 * _strcmp - strcmp
 * @str1: str1
 * @str2: str2
 *
 * Return: Returns the difference of the strings
 */
int _strcmp(const char *str1, const char *str2)
{
	int i, s1 = 0, s2 = 0, result = 0;

	for (i = 0; i > -1; i++)
	{
		if (str1[i] != str2[i])
		{
			s1 = str1[i];
			s2 = str2[i];
			break;
		}
		else
		{
			if (str1[i] == '\0' || str2[i] == '\0')
				break;
		}
	}
	result = s1 - s2;
	return (result);
}

/**
 * _strtok - strtok
 * @str: str
 * @delim: delim
 *
 * Return: ret
 */
char *_strtok(char *str, char delim)
{
	static char *tok1, *tok2;
	unsigned int i;

	if (str != NULL)
		tok2 = str;
	tok1 = tok2;
	if (tok1 == NULL)
		return (NULL);
	for (i = 0; tok1[i] != '\0'; i++)
	{
		if (tok1[i] != delim)
			break;
	}
	if (tok2[i] == '\0')
	{
		tok2 = NULL;
		return (NULL);
	}
	tok1 = tok2 + i;
	tok2 = tok1;
	for (i = 0; tok2[i] != '\0'; i++)
	{
		if (tok2[i] == delim)
			break;
	}
	if (tok2[i] == '\0')
		tok2 = NULL;
	else
	{
		tok2[i] = '\0';
		tok2 += i + 1;
		if (tok2[0] == '\0')
			tok2 = NULL;
	}
	return (tok1);
}

/**
 * _strlen - count str
 * @s: str
 *
 * Return: count str
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}