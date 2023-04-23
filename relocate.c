#include "shell.h"

/**
** _memset - it fills memory with a constant byte
** @s: it is the pointer to the memory area
** @b: it is the byte to fill *s with
** @n: it isthe amount of bytes to be filled
** Return: (s) a pointer to the memory area s
**/

char *_memset(char *s, char b, unsigned int n)

{
	unsigned int c;

	for (c = 0; c < n; c++)
		s[c] = b;
	return (s);

}

/**
** ffree - it frees a string of strings
** @pp: the string of strings
**/

void ffree(char **pp)

{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
** _realloc - it reallocates a block of memory
** @ptr: it is the pointer to previous malloc'ated block
** @old_size: the byte size of previous block
** @new_size: the byte size of new block
** Return: it is pointer to da ol'block nameen.
**/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)

{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);
	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;

	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
