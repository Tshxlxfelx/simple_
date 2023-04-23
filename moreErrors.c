#include "shell.h"

/**
 * atoi_err - converts a string to an integer
 * @str: the string to be converted
 *
 * Return: the converted number if successful, -1 on error
 */
int atoi_err(const char *str)
{
unsigned long int result = 0;

if (*str == '+')
str++;

for (; *str != '\0'; str++)
{
if (*str >= '0' && *str <= '9')
{
result *= 10;
result += (*str - '0');
if (result > INT_MAX)
return (-1);
}
else
{
return (-1);
}
}
return (result);
}

/**
 * print_error_message - prints an error message
 * @info: a struct containing information about the command and its arguments
 * @error_type: the type of error to be printed
 */
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}

/**
 * print_integer - prints an integer to the specified file descriptor
 * @n: the integer to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of characters printed
 */
int print_integer(int n, int fd)
{
int (*print_char)(char) = _putchar;
int i, count = 0;
unsigned int absolute_value, current;

if (fd == STDERR_FILENO)
print_char = _eputchar;

if (n < 0)
{
absolute_value = -n;
print_char('-');
count++;
}
else
{
absolute_value = n;
}

current = absolute_value;

for (i = 1000000000; i > 1; i /= 10)
{
if (absolute_value / i)
{
print_char('0' + current / i);
count++;
}
current %= i;
}

print_char('0' + current);
count++;

return (count);
}

/**
 * convert_number - converts a number to a string in the specified base
 * @num: the number to be converted
 * @base: the base to be used for the conversion
 * @flags: flags that specify additional conversion options
 *
 * Return: a string containing the converted number
 */
char *convert_number(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}

array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do {
*--ptr = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*--ptr = sign;

return (ptr);
}

/**
 * remove_comments - removes comments from a string
 * @buf: the string to modify
 *
 * This function replaces the first occurrence of '#' with '\0'
 * if '#' is preceded by a space or if it is the beginning of the string.
 * Return: void
 */
void remove_comments(char *buf)
{
int i = 0;

while (buf[i] != '\0')
{
if (buf[i] == '#' && (i == 0 || buf[i - 1] == ' '))
{
buf[i] = '\0';
break;
}
i++;
}
}


