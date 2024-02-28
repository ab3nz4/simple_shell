#include "shellHead.h"
/**
 * o_exit - the function closes the simple_shell
 * @parag: pointer with the direction argument.
 * @p_o_tr: standar input string
 * @_out_: value of exit
 * Return: None
 */
void o_exit(char **parag, char *p_o_tr, int _out_)
{
	int e_co = 0;

	if (!parag[1])
	{
		free(p_o_tr);
		free(parag);
		exit(_out_);
	}
	e_co = atoi(parag[1]);

	free(p_o_tr);
	free(parag);
	exit(e_co);
}

