#include "shellHead.h"
/**
 * o_pick - function that create a fork
 *@pg: command and values path
 *@argv: Has the name of our program
 *@e_s: environment
 *@ptr: command line for the user
 *@nerp: id of proces
 *@carma: Checker add new test
 *Return: 0 success
 */

int o_pick(char **pg, char **argv, char **e_s, char *ptr, int nerp, int carma)
{
	pid_t child;
	int state;
	char *format = "%s: %d: %s: not found\n";

	child = fork();

	if (child == 0)
	{
		if (execve(pg[0], pg, e_s) == -1)
		{
			fprintf(stderr, format, argv[0], nerp, pg[0]);
			if (!carma)
				free(pg[0]);
			free(pg);
			free(ptr);
			exit(errno);
		}
	}
	else
	{
		wait(&state);

		if (WIFEXITED(state) && WEXITSTATUS(state) != 0)
			return (WEXITSTATUS(state));
	}
	return (0);
}
