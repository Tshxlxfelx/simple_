#include "shell.h"

/**
** list_len - it determines length of linked list
** @h: it is the pointer to first node
** Return: it is the size of list
**/

size_t list_len(const list_t *h)

{
	size_t z = 0;

	while (h)
	{
		h = h->next;
		z++;
	}
	return (z);
}

/**
** list_to_strings - it returns an array of strings of the list->str
** @head: it is the pointer to first node
** Return: it is the array of strings
**/

char **list_to_strings(list_t *head)

{
	list_t *node = head;

	size_t i = list_len(head), p;

	char **strs;

	char *str;

	if (!head || !i)
		return (NULL);

	strs = malloc(sizeof(char *) * (i + 1));

	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);

		if (!str)
		{
			for (p = 0; p < i; p++)

				free(strs[p]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
** print_list - it prints all elements of a list_t linked list
** @h: it is the pointer to first node
** Return: the size of list
**/

size_t print_list(const list_t *h)

{
	size_t z = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		z++;
	}
	return (z);

}


/**
** node_starts_with - it returns node whose string starts with prefix
** @node: it is the pointer to list head
** @prefix: the string to match
** @c: it is the next character after prefix to match
** Return: to match node or null
**/

list_t *node_starts_with(list_t *node, char *prefix, char c)

{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);

		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
** get_node_index - it gets the index of a node
** @head: the pointer to list head
** @node: the pointer to the node
** Return: the index of node or -1
**/

ssize_t get_node_index(list_t *head, list_t *node)

{
	size_t z = 0;

	while (head)
	{
		if (head == node)
			return (z);
		head = head->next;
		z++;
	}
	return (-1);

}
