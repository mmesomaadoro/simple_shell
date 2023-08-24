#include "main.h"

/**
 * _forkProcess - function that create a new process
 * @av: pointer to array of string to be freed
 * @cmd: command used
 * @buf: memory to be freed
 * @env: environment variables
 * @ex: exit status
 * Return: void
 */
int _forkProcess(char **av, char *cmd, char *buf, char **env, int ex)
{
	pid_t pid = fork();
	int status = 0;

	if (pid == -1)
	{
		_freeAV(av), free(buf);
		perror(PROG_NAME);
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(cmd, av, env) == -1)
		{
			_freeAV(av), free(buf);
			perror(PROG_NAME);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			ex = WEXITSTATUS(status);
		}
	}
	return (ex);
}
