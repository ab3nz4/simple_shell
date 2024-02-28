#include "shellHead.h"
/**
 * o_pick - function that create a fork
 *@parag: command and values path
 *@argv: Has the name of our program
 *@env_scap: environment
 *@p_o_tr: command line for the user
 *@nerp: id of proces
 *@carma: Checker add new test
 *Return: 0 success
 */

int o_pick(char **parag, char **argv, char **env_scap, char *p_o_tr, int nerp, int carma)
{
	pid_t child;
	int state;
	char *format = "%s: %d: %s: not found\n";

	child = fork();

	if (child == 0)
	{
		if (execve(parag[0], parag, env_scap) == -1)
		{
			fprintf(stderr, format, argv[0], nerp, parag[0]);
			if (!carma)
				free(parag[0]);
			free(parag);
			free(p_o_tr);
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
