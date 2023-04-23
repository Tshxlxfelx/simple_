#include "shell.h"

/**
 * split_string - splits a string into words using a delimiter string
 * @str: the input string
 * @delim: the delimiter string
 *
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **split_string(char *str, char *delim)
{
if (str == NULL || delim == NULL)
return (NULL);

int num_words = 0;
char **words = NULL;
char *token = strtok(str, delim);

while (token != NULL)
{
num_words++;
words = realloc(words, num_words *sizeof(char *));
if (words == NULL)
goto fail;

words[num_words - 1] = strdup(token);
if (words[num_words - 1] == NULL)
goto fail;

token = strtok(NULL, delim);
}

/* Add a NULL at the end of the array */
num_words++;
words = realloc(words, num_words *sizeof(char *));
if (words == NULL)
goto fail;
words[num_words - 1] = NULL;

return (words);

fail:
/* Free the previously allocated words */
for (int i = 0; i < num_words; i++)
{
free(words[i]);
}
free(words);

return (NULL);
}

