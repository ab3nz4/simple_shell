#include "shellHead.h"
/**
 *o_strconcat - copy string to another string.
 *@dest: char
 *@src: char
 *Return: dest
 *
 */

char *o_strconcat(char *dest, char *src)
{
	int init = 0;
	int init2 = 0;

	while (dest[init] != '\0')
	{
		init++;
	}
	while (src[init2] != '\0')
	{
		dest[init] = src[init2];
		init++;
		init2++;
	}
	dest[init] = '\0';
	return (dest);
}

/**
 * o_strcomp - compare the values of a string
 * @str1: character
 * @str2: character
 * Return: 0
 */

int o_strcomp(char *str1, char *str2)
{
	int a;

	for (a = 0; str1[a] != '\0' && str2[a] != '\0'; a++)
	{
		if (str1[a] != str2[a])
			return ((int)str1[a] - str2[a]);
	}
	return (0);
}

/**
 * o_str_length - copies the string pointed 
 * @string: A pointer
 * Return: char pointer to dest
 */

int o_str_length(char *string)
{
	int ch = 0;

	while (*(string + ch) != '\0')
	{
		ch++;
	}

	return (ch);
}

/**
 *o_str_n_comp -  function that compares two strings.
 *@str1: string one
 *@str2: string two
 *@n: number of characters
 * Return: diference
 */

size_t o_str_n_comp(char *str1, char *str2, size_t n)
{
	size_t i, j;

	for (j = 0; str1[j] != '\0' && j < n; j++)
	{
		i = str1[j] - str2[j];

		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}

/**
 * o_strcopy - copies the string pointed 
 * @dest: destination of the copy
 * @src: source of the copy
 *
 * Return: char pointer to dest
 */

char *o_strcopy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = *(src + i);

	return (dest);
}
