#include "main.h"

/**
 * _strlen - function that gets the length of a string
 * @str: string used
 * Return: integer
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * _strcpy - function that copies a strings
 * @dst: string destination
 * @src: string to be copied
 * Return: string
 */
char *_strcpy(char *dst, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';

	return (dst);
}

/**
 * _strcat - function that concatenates a string
 * @dst: string destination
 * @src: string to be concatenated
 * Return: string
 */
char *_strcat(char *dst, char *src)
{
	int i, count, dstLen;

	count = _strlen(dst);
	dstLen = count;

	for (i = 0; src[i] != '\0'; i++)
	{
		dst[count + i] = src[i];
		dstLen++;
	}
	dst[dstLen] = '\0';

	return (dst);
}

/**
 * _strcmp - function that compares two strings
 * @s1: first string to be compared
 * @s2: second string to be compared
 * Return: integer
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (0);
}

/**
 * _strdup - function that duplicates a string
 * @src: string to be duplicated
 * Return: string
 */
char *_strdup(char *src)
{
	size_t len = _strlen(src);

	char *dst = malloc(len + 1);

	if (dst)
		_strcpy(dst, src);

	return (dst);
}
