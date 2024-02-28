#include "shellHead.h"
/**
 * o_path_find - get variable PATH.
 * @env_scap: enviromente local
 * Return: value of PATH.
 */

char *o_path_find(char **env_scap)
{
	size_t index = 0, unk = 0, count = 5;
	char *path = NULL;

	while (env_scap[index] != NULL && o_str_n_comp(env_scap[index], "PATH=", 5) != 0)
		index++;
	if (env_scap[index] == NULL)
		return (NULL);

	while (env_scap[index][unk] != '\0')
		unk++;
	count = unk - 5;
	path = malloc(sizeof(char) * (count + 1));

	if (path == NULL)
		return (NULL);

	unk = 5;
	for (count = 0; env_scap[index][unk] != '\0'; unk++, count++)
		path[count] = env_scap[index][unk];

	path[count] = '\0';
	return (path);
}
