#include "shell.h"

/**
** is_cmd - it determines if a file is an executable command
** @info: it is the info struct
** @path: the path to the file
** Return: 1 if true, 0 otherwise
**/

int is_cmd(info_t *info, char *path)

{
	struct stat st;

	(void)info;

	if (!path || stat(path, &st))
		return (0);
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
** dup_chars - it duplicates characters
** @pathstr: it is the PATH string
** @start: the starting index
** @stop: the stopping index
** Return: the pointer to new buffer
**/

char *dup_chars(char *pathstr, int start, int stop)

{
	static char buf[1024];

	int t = 0, g = 0;

	for (g = 0, t = start; t < stop; t++)
		if (pathstr[t] != ':')
			buf[g++] = pathstr[t];
	buf[g] = 0;
	return (buf);
}

/**
** find_path - it finds this cmd in the PATH string
** @info: it is the info struct
** @pathstr: it is the PATH string
** @cmd: it is the cmd to find
** Return: the full path of cmd if found or NULL
**/

char *find_path(info_t *info, char *pathstr, char *cmd)

{
	int m = 0, curr_pos = 0;

	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[m] || pathstr[m] == ':')
		{
			path = dup_chars(pathstr, curr_pos, m);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[m])
				break;
			curr_pos = m;
		}
		m++;
	}
	return (NULL);
}


