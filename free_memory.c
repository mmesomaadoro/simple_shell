#include "main.h"

/**
 * _freeAV - function that frees allocated memory
 * for array of strings and the array itself
 * @mem: pointer to array of string
 * Return: void
 */
void _freeAV(char **mem)
{
	int i;

	for (i = 0; mem[i]; i++)
	{
		free(mem[i]);
	}
	free(mem);
}

