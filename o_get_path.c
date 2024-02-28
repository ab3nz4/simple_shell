#include "shellHead.h"
/**
 * o_path_find - get variable PATH.
 * @e_s: enviromente local
 * Return: value of PATH.
 */

char *o_path_find(char **e_s)
{
	size_t index = 0, unk = 0, count = 5;
	char *path = NULL;

	while (e_s[index] != NULL && o_n_cmp(e_s[index], "PATH=", 5) != 0)
		index++;
	if (e_s[index] == NULL)
		return (NULL);

	while (e_s[index][unk] != '\0')
		unk++;
	count = unk - 5;
	path = malloc(sizeof(char) * (count + 1));

	if (path == NULL)
		return (NULL);

	unk = 5;
	for (count = 0; e_s[index][unk] != '\0'; unk++, count++)
		path[count] = e_s[index][unk];

	path[count] = '\0';
	return (path);
}
