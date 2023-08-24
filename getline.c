#include "main.h"

/**
 * _getline - function that gets command line from user
 * @buf: temporary storage for command line
 * Return: void
 */
size_t _getline(char **buf)
{
	size_t n = 0, len = 0;
	ssize_t bytes_rd;

	bytes_rd = getline(buf, &n, stdin);
	if (bytes_rd == EOF)
	{
		free(*buf);
		exit(127);
	}

	len = bytes_rd - 1;
	(*buf)[len] = '\0';

	while (len > 0 && ((*buf)[len - 1] == ' ' || (*buf)[len - 1] == '\t'))
		(*buf)[--len] = '\0';

	return (len);
}
