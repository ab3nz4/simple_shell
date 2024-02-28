#include "shellHead.h"
/**
 * abpaz - separate the paz.
 * @parag: cmd inp.
 * @env_scap: place.
 * Return:  a pointer to strings.
 */
int abpaz(char **parag, char **env_scap)
{
	char *token = NULL, *path_rela = NULL, *path_absol = NULL;
	size_t value_path, command;
	struct stat stat_lineptr;

	if (stat(*parag, &stat_lineptr) == 0)
		return (-1);
	path_rela = o_path_find(env_scap);
	if (!path_rela)
		return (-1);
	token = o_toks(path_rela, ":");
	command = o_str_length(*parag);
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
		o_strconcat(path_absol, *parag);

		if (stat(path_absol, &stat_lineptr) == 0)
		{
			*parag = path_absol;
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
 *o_get_environ - function to get all env_scap
 *@env_scap: enviroment
 *Return: 0
 */

void o_get_environ(char **env_scap)
{
	size_t run = 0;

	while (env_scap[run])
	{
		write(STDOUT_FILENO, env_scap[run], o_str_length(env_scap[run]));
		write(STDOUT_FILENO, "\n", 1);
		run++;
	}
}