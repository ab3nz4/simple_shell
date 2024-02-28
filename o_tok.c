#include "shellHead.h"
/**
 * o_get_toktok - get token of string
 * @p_o_tr: comman user
 * Return: To a pointer
 */

char **o_get_toktok(char *p_o_tr)
{
	char **propme = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;

	if (p_o_tr == NULL)
		return (NULL);

	for (i = 0; p_o_tr[i]; i++)
	{
		if (p_o_tr[i] == ' ')
			size++;
	}
	if ((size + 1) == o_str_length(p_o_tr))
		return (NULL);
	propme = malloc(sizeof(char *) * (size + 2));
	if (propme == NULL)
		return (NULL);

	token = o_toks(p_o_tr, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		propme[i] = token;
		token = o_toks(NULL, " \n\t\r");
	}
	propme[i] = NULL;
	return (propme);
}
