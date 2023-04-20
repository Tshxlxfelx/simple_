#include "shell.h"

/**
 * input_buf - read input from standard input and buffer chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read or -1 on failure
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t n_read = 0;
size_t buf_size = 0;

if (*len == 0)
{
free(*buf);
*buf = NULL;

signal(SIGINT, sigintHandler);

n_read = getline(buf, &buf_size, stdin);
if (n_read == -1)
{
return (-1);
}

if ((*buf)[n_read - 1] == '\n')
{
(*buf)[n_read - 1] = '\0'; /* remove trailing newline */
n_read--;
}

info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);

/* check if the input contains chained commands */
if (strchr(*buf, ';'))
{
*len = n_read;
info->cmd_buf = buf;
}
else
{
*len = 0;
}
}
else
{
n_read = *len;
*len = 0;
}

return (n_read);
}
/**
 * get_input - read input from standard input and handle chained commands
 * @info: parameter struct
 *
 * Return: bytes read or -1 on failure
 */
ssize_t get_input(info_t *info)
{
static char *cmd_buf = NULL;
static size_t cmd_pos = 0, cmd_len = 0;
ssize_t n_read = 0;
char **arg_buf = &(info->arg);

_putchar(BUF_FLUSH);
n_read = input_buf(info, &cmd_buf, &cmd_len);
if (n_read == -1) /* EOF */
{
return (-1);
}

if (cmd_len) /* we have commands left in the chain buffer */
{
size_t next_cmd_pos = cmd_pos;
char *next_cmd = cmd_buf + cmd_pos;
check_chain(info, cmd_buf, &next_cmd_pos, cmd_pos, cmd_len);

/* find the end of the current command or the next semicolon */
while (next_cmd_pos < cmd_len && !is_chain(info, cmd_buf, &next_cmd_pos))
{
next_cmd_pos++;
}

/* if we found a semicolon, increment past it */
if (next_cmd_pos < cmd_len)
{
next_cmd_pos++;
}

cmd_pos = next_cmd_pos;
cmd_len -= next_cmd_pos;

/* reset the buffer position and type if we've reached the end */
if (cmd_len == 0)
{
cmd_pos = 0;
info->cmd_buf_type = CMD_NORM;
}

*arg_buf = next_cmd; /* pass back pointer to current command position */
return (strlen(next_cmd)); /* return length of current command */
}

/* if there are no chained commands, pass back the entire buffer */
*arg_buf = cmd_buf;
return (n_read);
}
#include "shell.h"

/**
 * _getline - reads a line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: number of bytes read
 */
ssize_t _getline(info_t *info, char **ptr, size_t *length)
{
ssize_t nread;
size_t size = 0;
char *buf = NULL;
char *p = *ptr;

/* If buffer is preallocated and not null, use it */
if (p && length && *length > 0)
{
buf = p;
size = *length;
}

/* Use getline to read a line from STDIN */
nread = getline(&buf, &size, stdin);
if (nread == -1)
{
if (buf)
free(buf);
return (-1);
}

/* Remove newline character from the end of the string */
if (nread > 0 && buf[nread - 1] == '\n')
buf[nread - 1] = '\0';

/* Reallocate the buffer to the actual size of the string */
if (ptr)
*ptr = realloc(buf, nread);

/* Set the buffer length if length parameter is provided */
if (length)
*length = nread;

return (nread);
}
/**
* sigintHandler - blocks ctrl-C
* @sig_num: the signal number
*
* Return: void
*/
void sigintHandler(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}
