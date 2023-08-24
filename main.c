#include "main.h"

/**
 * main - function that starts the program
 * @ac: argument count
 * @av: argument vector
 * @envp: environment variables
 * Return: integer
 */
int main(int ac, char **av, char *envp[])
{
	char **token, *storage = NULL, *pathFind;
	size_t len;
	int ex = 0;
	(void)ac;

	while (1)
	{
		_prompt();
		len = _getline(&storage);

		if (len == 0)
			continue;

		if (storage[0] != '\0')
		{
			token = _getToken(av, storage);
			_exitHandler(ex, token, storage);
			_envHandler(envp, token);

			pathFind = _findCMD(token[0], envp);
			if (pathFind)
			{
				_forkProcess(token, pathFind, storage, envp, ex);
				free(pathFind);
			}
			else
			{
				perror(PROG_NAME);
				ex = 127;
			}
			_freeAV(token);
		}
		free(storage);
	}
	return (ex);
}
