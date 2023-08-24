#include "main.h"

/**
 * _exitHandler - function that terminates or exit the shell
 * @ex: exit status
 * @av: argument vector
 * @buf: buffer to be freed
 * Return: void
 */
void _exitHandler(int ex, char **av, char *buf)
{
	if (_strcmp(av[0], "exit") == 0)
	{
		_freeAV(av), free(buf);
		exit(ex);
	}
}
