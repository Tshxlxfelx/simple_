#include "shell.h"

/**
* bfree - it frees a pointer and it NULLs the address
** @ptr: it is the address of the pointer to free
** Return: 1 should be returned if freed, or 0 if not freed.
**/

int bfree(void **ptr)

{
	if (ptr && *ptr)
	{free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);

}
