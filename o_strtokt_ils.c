#include "shellHead.h"

/**
 * o_toks - breaks the string str1 into tokens
 * @str: string to tokenize
 * @delim: string with the char.
 * Return: the first/next token
 **/
char *o_toks(char *str, const char *delim)
{
	static char *p;
	size_t len;

	if (!str)
		str = p;

	if (!str)
		return (0);

	len = o_strspin(str, delim);

	if (len == strlen(str))
		return (0);

	p = str + len + o_strspun(str + len, delim);
	*p = 0;
	p++;

	return (str);
}
/**
 * o_strspun - com the length of the max
 * @str1: string to check
 * @str2: string useful to compare
 * Return: the len.
 **/
size_t o_strspun(const char *str1, const char *str2)
{
	size_t ho = 0;

	while (*str1)
	{
		if (o_strchart(str2, *str1))
			return (ho);
		str1++, ho++;
	}
	return (ho);
}
/**
 * o_strspin - computes the length
 * @str1: length computer
 * @str2: delimiter
 * Return: the length.
 **/
size_t o_strspin(const char *str1, const char *str2)
{
	size_t ho = 0;

	while (*str1 && o_strchart(str2, *str1++))
		ho++;
	return (ho);
}
/**
 * o_strchart - find first occur
 * @string: string
 * @carma: character
 * Return: a pointer to the char
 **/
char *o_strchart(const char *string, int carma)
{
	while (*string != (char)carma)
		if (!*string++)
			return (0);
	return ((char *)string);
}
