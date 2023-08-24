#include "main.h"

/**
 * _freeAV - function that frees allocated memory
 * for array of strings and the array itself
 * @av: pointer to array of string
 * Return: void
 */
void _freeAV(char **av)
{
	int i;

	for (i = 0; av[i]; i++)
	{
		free(av[i]);
	}
	free(av);
}

