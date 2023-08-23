#include "main.h"

/**
 * _exitHandler - function that terminates or exit the shell
 * @ac: argument count
 * @av: argument vector
 * @buf: buffer to be freed
 * Return: void
 */
void _exitHandler(int ac, char **av, char *buf)
{
	if (ac == 1 && _strcmp(av[0], "exit") == 0)
	{
		_freeAV(av), free(buf);
		exit(EXIT_SUCCESS);
	}
}
