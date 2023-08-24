#include "main.h"

/**
 * _envHandler - function that prints env variables
 *  @env: environment variables
 *  @av: argument vector
 *  Return: void
 */
void _envHandler(char **env, char **av)
{
	size_t i, len;

	if (_strcmp(av[0], "env") == 0)
	{
		for (i = 0; env[i] != NULL; i++)
		{
			len = _strlen(env[i]);
			write(STDOUT_FILENO, env[i], len);
			write(STDOUT_FILENO, "\n", 1);
		}
	}
}

