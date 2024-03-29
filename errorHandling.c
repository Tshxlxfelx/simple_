#include "shell.h"

/**
 * _eputs - prints an input string to stderr
 * @str: the string to be printed
 */
void _eputs(char *str)
{
if (str == NULL)
return;
while (*str != '\0')
_eputchar(*str++);
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
static char buf[WRITE_BUF_SIZE];
static int i;

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(STDERR_FILENO, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;

return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
static char buf[WRITE_BUF_SIZE];
static int i;

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * _putsfd - prints an input string to the given file descriptor
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of characters printed
 */
int _putsfd(char *str, int fd)
{
int count = 0;
if (str == NULL)
return (0);
while (*str != '\0')
{
count += _putfd(*str++, fd);
}
return (count);
}

