#include "main.h"

/**
 * _getTokenLen - function that gets the length of a token
 * @buf: memory to be tokenize in order to get the length
 * Return: integer
 */
size_t _getTokenLen(char *buf)
{
	char *bufCopy, *token;
	const char *delim = " \n";
	size_t len;

	bufCopy = _strdup(buf);
	if (!bufCopy)
	{
		free(buf);
		return (-1);
	}

	token = strtok(bufCopy, delim);
	for (len = 0; token; len++)
		token = strtok(NULL, delim);

	free(bufCopy);
	return (len);
}

/**
 * _getToken - function that gets the token
 * @av: pointer to array of strings
 * @buf: memory to be tokenize
 * Return: pointer to array of strings
 */
char **_getToken(char **av, char *buf)
{
	char *token;
	const char *delim = " \n";
	size_t len;

	len = _getTokenLen(buf);
	av = malloc(sizeof(char *) * (len + 1));
	if (!av)
	{
		free(buf);
		return (NULL);
	}

	token = strtok(buf, delim);
	for (len = 0; token; len++)
	{
		av[len] = _strdup(token);
		if (!av[len])
		{
			free(av), free(buf);
			return (NULL);
		}
		token = strtok(NULL, delim);
	}
	av[len] = NULL;
	return (av);
}
