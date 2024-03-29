#include "shellHead.h"
/**
 * o_get_toktok - get token of string
 * @ptr: comman user
 * Return: To a pointer
 */

char **o_get_toktok(char *ptr)
{
	char **propme = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;

	if (ptr == NULL)
		return (NULL);

	for (i = 0; ptr[i]; i++)
	{
		if (ptr[i] == ' ')
			size++;
	}
	if ((size + 1) == o_str_length(ptr))
		return (NULL);
	propme = malloc(sizeof(char *) * (size + 2));
	if (propme == NULL)
		return (NULL);

	token = o_toks(ptr, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		propme[i] = token;
		token = o_toks(NULL, " \n\t\r");
	}
	propme[i] = NULL;
	return (propme);
}
