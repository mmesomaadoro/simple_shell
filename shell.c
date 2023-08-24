#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

char *getPath(char *cmd);
int _strlen(char *str);
char *_strcpy(char *dst, char *src);
char *_strcat(char *dst, char *src);
int _strcmp(char *str1, char *str2);
char *_strdup(char *src);

/**
 * main - program start
 * @argc: argument count
 * @argv: argument vector
 * @env: envirinment variables
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	char *linePtr = NULL, *fullPath, *string_token;
	char **av;
	size_t buffersize = 0, len, numalloc = 200;
	int i, count, mode = isatty(0), c_process, line, status = 0, ex = 0;
	(void)argc;

	for (;;)
	{
		if (mode == 1)
			write(1, "$ ", 2);
		line = getline(&linePtr, &buffersize, stdin);
		if (line == -1)
		{
			free(linePtr);
			exit(127);
		}
		linePtr[line - 1] = '\0';

		len = _strlen(linePtr);
		while (len > 0 && (linePtr[len - 1] == ' ' || linePtr[len - 1] == '\t'))
		{
			linePtr[--len] = '\0';
		}
		if (len == 0)
			continue;
		if (linePtr[0] != '\0')
		{
			av = malloc(sizeof(char *) * (numalloc + 1));
			if (!av)
				continue;
			string_token = strtok(linePtr, " \n\t\r");
			for (count = 0; string_token != NULL; count++)
			{
				av[count] = string_token;
				string_token = strtok(NULL, " \n\t\r");
			}
			av[count] = NULL;

			if (_strcmp(av[0], "exit") == 0)
			{
				free(av);
				exit(ex);
			}

			if (_strcmp(av[0], "env") == 0)
			{
				for (i = 0; env[i] != NULL; i++)
				{
					len = _strlen(env[i]);
					write(STDOUT_FILENO, env[i], len);
					write(STDOUT_FILENO, "\n", 1);
				}
				free(av);
				continue;
			}

			fullPath = getPath(av[0]);

			if (fullPath)
			{
				c_process = fork();
				if (c_process == 0)
				{
					if (execve(fullPath, av, env) == -1)
					{
						perror(argv[0]);
						free(av);
						exit(2);
					}
				}
				else
				{
					wait(&status);
					if (WIFEXITED(status))
					{
						ex = WEXITSTATUS(status);
					}
					free(av);
				}
				free(fullPath);
			}
			else
			{
				perror(argv[0]);
				ex = 127;
				free(av);
			}
		}
	}
	free(linePtr);
	return (ex);
}
