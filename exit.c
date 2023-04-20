#include "shell.h"

/**
**_strncpy - it copies a string
**@dest: it is the destination string to be copied to
**@src: source string
**@n: it is the amount of characters to be copied
**Return: it is the concatenated string
**/

char *_strncpy(char *dest, char *src, int n)

{
	int z, m;

	char *s = dest;

	z = 0;
	while (src[z] != '\0' && z < n - 1)
	{
		dest[z] = src[z];
		z++;
	}
	if (z < n)
	{
		m = z;
		while (m < n)
		{
			dest[m] = '\0';
			m++;
		}
	}
	return (s);
}

/**
**_strncat - it concatenates two strings
**@dest: it is the first string
**@src: it is the second string
**@n: it is the amount of bytes to be maximally used
**Return: it is the concatenated string
**/

char *_strncat(char *dest, char *src, int n)

{
	int z, m;

	char *s = dest;

	z = 0;
	m = 0;

	while (dest[z] != '\0')
		z++;
	while (src[m] != '\0' && m < n)
	{
		dest[z] = src[m];
		z++;
		m++;
	}
	if (m < n)
		dest[z] = '\0';
	return (s);
}

/**
**_strchr - it locates a character in a string
**@s: it is the string to be parsed
**@c: it is the character to look for
**Return: (s) it is a pointer to the memory area s
**/

char *_strchr(char *s, char c)

{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	return (NULL);

}
