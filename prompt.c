#include "main.h"

/**
 * _prompt - function that prints prompt message to standard output
 * Return: void
 */
void _prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, PROMPT, PROMPT_LEN);
}
