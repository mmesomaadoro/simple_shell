#include "main.h"

/**
 * _getenv - function that get environment varaibles
 * @var_name: variable name
 * @envp: environment variables
 * Return: list of all environment variables
 */
char *_getenv(char *var_name, char **envp)
{
	int i = 0;
	char *env, *token, *value = NULL;

	while (envp[i])
	{
		env = strdup(envp[i]);
		token = strtok(env, "=");

		if (_strcmp(token, var_name) == 0)
		{
			value = strdup(strtok(NULL, "="));
			free(env);
			return (value);
		}
		i++;
		free(env);
	}
	return (NULL);
}
