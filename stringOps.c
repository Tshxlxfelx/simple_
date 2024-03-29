#include "shell.h"

/**
 * _strcpy - Copies a string.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: Pointer to the destination string.
 */
char *_strcpy(char *dest, const char *src)
{
int i = 0;

if (dest == src || src == NULL)
return (dest);

while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}

dest[i] = '\0';
return (dest);
}

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string.
 */
char *_strdup(const char *str)
{
int length = 0;
char *ret;

if (str == NULL)
return (NULL);
while (str[length] != '\0')
length++;

ret = malloc(sizeof(char) * (length + 1));

if (ret == NULL)
return (NULL);

_strcpy(ret, str);
return (ret);
}

/**
 * _puts - Prints a string to stdout.
 * @str: The string to be printed.
 */
void _puts(const char *str)
{
int i = 0;

if (str == NULL)
return;

while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
}

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written.
 *
 * Return: On success, 1.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(1, buf, i);
i = 0;
}

if (c != BUF_FLUSH)
buf[i++] = c;

return (1);
}

