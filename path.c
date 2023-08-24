#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * getPath - function that gets the path of a command
 * @cmd: command to get it's path
 * Return: fullPath if successful otherwise NULL
 */
char *getPath(char *cmd)
{
	char *path, *path_copy, *token, *full_path;

	if (access(cmd, X_OK) == 0)
	{
		full_path = strdup(cmd);
		if (full_path == NULL)
			return (NULL);
		return (full_path);
	}
	path = getenv("PATH");
	if (path == NULL)
		return (NULL);
	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		/* Construct the full path by directory concat and command */
		full_path = malloc(strlen(token) + strlen(cmd) + 2);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, cmd);
		/* Check if the constructed path exists */
		if (access(full_path, F_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
