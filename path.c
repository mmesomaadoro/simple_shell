#include "main.h"

/**
 * _pathConcat - function that concatenates full path of a path
 * @cmd: command to be tokenize
 * @tok: token of the path gotten
 * Return: string
 */
char *_pathConcat(char *cmd, char *tok)
{
	char *fullPath;

	fullPath = malloc(_strlen(tok) + _strlen(cmd) + 2);
	if (!fullPath)
	{
		return (NULL);
	}

	_strcpy(fullPath, tok);
	_strcat(fullPath, "/");
	_strcat(fullPath, cmd);
	_strcat(fullPath, "\0");

	return (fullPath);
}

/**
 * _findCMD - function that searches for the command if it is executable or not
 * @cmd: command to be executed
 * @envp: environment variables
 * Return: string
 */
char *_findCMD(char *cmd, char **envp)
{
	char *path, *pathCpy, *pathToken, *fullPath, *result = NULL;
	const char *pathDelim = ":";
	struct stat fileInfo;

	if (access(cmd, X_OK) == 0)
		return (_strdup(cmd));

	path = _getenv("PATH", envp);
	if (!path)
		return (NULL);
	pathCpy = _strdup(path);
	if (!pathCpy)
	{
		free(path);
		return (NULL);
	}

	pathToken = strtok(pathCpy, pathDelim);

	while (pathToken)
	{
		fullPath = _pathConcat(cmd, pathToken);

		if (stat(fullPath, &fileInfo) == 0)
		{
			result = _strdup(fullPath);
			free(fullPath);
			break;
		}

		free(fullPath);
		pathToken = strtok(NULL, pathDelim);
	}

	free(pathCpy);
	free(path);

	return (result);
}
