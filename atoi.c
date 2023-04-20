#include "shell.h"

/**
** interactive - it should returns true if shell is interactive mode
** @info: it is a struct address
** Return: 1 if it is in an interactive mode, 0 otherwise
**/

int interactive(info_t *info)

{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);

}

/**
** is_delim - it checks if character is a delimeter
** @c: it is the char to check
** @delim: it is the delimeter string
** Return: 1 if it is true, 0 if false
**/

int is_delim(char c, char *delim)

{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);

}

/**
** _isalpha - it checks for alphabetic character
** @c: it is The character to input
** Return: 1 if c is alphabetic, 0 if otherwise
**/

int _isalpha(int c)

{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
** _atoi - it  converts a string to an integer
** @s: it is the string to be converted
** Return: 0 if no numbers in string, converted number otherwise
**/

int _atoi(char *s)

{
	int b, sign = 1, flag = 0, output;

	unsigned int result = 0;

	for (b = 0; s[b] != '\0' && flag != 2; b++)
	{
		if (s[b] == '-')
			sign *= -1;
		if (s[b] >= '0' && s[b] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[b] - '0');
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
