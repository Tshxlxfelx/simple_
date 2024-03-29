#include "shell.h"
/**
* **strtow - splits a string into words. Repeat delimiters are ignored
* @str: the input string
* @d: the delimeter string
* Return: a pointer to an array of strings, or NULL on failure
*/
char **strtow(char *str, char *d)
{
int i, a, b, c, numwords = 0;
char **s;
if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (i = 0; str[i] != '\0'; i++)
if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (i = 0, a  = 0; a < numwords; a++)
{
while (is_delim(str[i], d))
i++;
b = 0;
while (!is_delim(str[i + b], d) && str[i + b])
b++;
s[a] = malloc((b + 1) * sizeof(char));
if (!s[a])
{
for (b = 0; b < a; b++)
free(s[b]);
free(s);
return (NULL);
}
for (c = 0; c < b; c++)
s[a][c] = str[i++];
s[a][c] = 0;
}
s[a] = NULL;
return (s);
}
/**
* **strtow2 - splits a string into words
* @str: the input string
* @d: the delimeter
* Return: a pointer to an array of strings, or NULL on failure
*/
char **strtow2(char *str, char d)
{
int i, a, b, c, numwords = 0;
char **s;
if (str == NULL || str[0] == 0)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
if ((str[i] != d && str[i + 1] == d) ||
(str[i] != d && !str[i + 1]) || str[i + 1] == d)
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (i = 0, a = 0; a < numwords; a++)
{
while (str[i] == d && str[i] != d)
i++;
b = 0;
while (str[i + b] != d && str[i + b] && str[i + b] != d)
b++;
s[a] = malloc((b + 1) * sizeof(char));
if (!s[a])
{
for (b = 0; b < a; b++)
free(s[b]);
free(s);
return (NULL);
}
for (c = 0; c < b; c++)
s[a][c] = str[i++];
s[a][c] = 0;
}
s[a] = NULL;
return (s);
}
