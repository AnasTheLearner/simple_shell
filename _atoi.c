#include "shell.h"

/**
 * interactive - return true if shell is interactive mode
 * @info: address
 * Return: 1 if interactive mode, 0 if not
 */

int interactive(inftm *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - check if character is a delimeter.
 * @b: the char
 * @stri: delimeter string
 * Return: 1 if delimeter, 0 if not
 */

int is_delim(char b, char *stri)
{
	while (*stri)
		if (*stri++ == b)
			return (1);
	return (0);
}

/**
 * _isalpha - check for alphabetic char
 * @b: char
 * Return: 1 if c is alphabetic, 0 if not
 */

int _isalpha(int b)
{
	if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - convert a string to an int
 * @s: string
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
