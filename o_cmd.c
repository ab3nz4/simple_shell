#include "shellHead.h"
/**
 * o_cmd - print "$ " and wait.
 * Return: line of string
 */

char *o_cmd(void)
{
	char *p = NULL;
	size_t hm = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&p, &hm, stdin) == -1)
	{
		free(p);
		return (NULL);
	}

	return (p);
}
