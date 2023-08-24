#include "main.h"

/**
 * _envHandler - function that prints env variables
 *  @envp: environment variables
 *  @av: argument vector
 *  Return: void
 */
void _envHandler(char **envp, char **av)
{
	size_t i, len;

	if (_strcmp(av[0], "env") == 0)
	{
		for (i = 0; envp[i] != NULL; i++)
		{
			len = _strlen(envp[i]);
			write(STDOUT_FILENO, envp[i], len);
			write(STDOUT_FILENO, "\n", 1);
		}
	}
}

