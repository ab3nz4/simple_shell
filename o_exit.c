#include "shellHead.h"
/**
 * o_exit - the function closes the simple_shell
 * @pg: pointer with the direction argument.
 * @ptr: standar input string
 * @_out_: value of exit
 * Return: None
 */
void o_exit(char **pg, char *ptr, int _out_)
{
	int e_co = 0;

	if (!pg[1])
	{
		free(ptr);
		free(pg);
		exit(_out_);
	}
	e_co = atoi(pg[1]);

	free(ptr);
	free(pg);
	exit(e_co);
}

