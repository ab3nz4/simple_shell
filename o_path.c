#include "shellHead.h"
/**
 * abpaz - separate the paz.
 * @pg: cmd inp.
 * @e_s: place.
 * Return:  a pointer to strings.
 */
int abpaz(char **pg, char **e_s)
{
	char *token = NULL, *path_rela = NULL, *path_absol = NULL;
	size_t value_path, command;
	struct stat stat_lineptr;

	if (stat(*pg, &stat_lineptr) == 0)
		return (-1);
	path_rela = o_path_find(e_s);
	if (!path_rela)
		return (-1);
	token = o_toks(path_rela, ":");
	command = o_str_length(*pg);
	while (token)
	{
		value_path = o_str_length(token);
		path_absol = malloc(sizeof(char) * (value_path + command + 2));
		if (!path_absol)
		{
			free(path_rela);
			return (-1);
		}
		path_absol = o_strcopy(path_absol, token);
		o_strconcat(path_absol, "/");
		o_strconcat(path_absol, *pg);

		if (stat(path_absol, &stat_lineptr) == 0)
		{
			*pg = path_absol;
			free(path_rela);
			return (0);
		}
		free(path_absol);
		token = o_toks(NULL, ":");
	}
	free(path_rela);
	return (-1);
}

/**
 *o_get_environ - function to get all e_s
 *@e_s: enviroment
 *Return: 0
 */

void o_get_environ(char **e_s)
{
	size_t run = 0;

	while (e_s[run])
	{
		write(STDOUT_FILENO, e_s[run], o_str_length(e_s[run]));
		write(STDOUT_FILENO, "\n", 1);
		run++;
	}
}
