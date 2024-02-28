#include "shellHead.h"
/**
 * main - main arguments functions
 * @argc:count of argumnents
 * @argv: arguments
 * @env_scap: environment
 * Return: _out_ = 0.
 */
int main(int argc, char **argv, char **env_scap)
{
	char *getcommand = NULL, **user_command = NULL;
	int pa_v = 0, _out_ = 0, n = 0;
	(void)argc;

	while (1)
	{
		getcommand = o_cmd();
		if (getcommand)
		{
			pa_v++;
			user_command = o_get_toktok(getcommand);
			if (!user_command)
			{
				free(getcommand);
				continue;
			}
			if ((!o_strcomp(user_command[0], "exit")) && user_command[1] == NULL)
				o_exit(user_command, getcommand, _out_);
			if (!o_strcomp(user_command[0], "env_scap"))
				o_get_environ(env_scap);
			else
			{
				n = abpaz(&user_command[0], env_scap);
				_out_ = o_pick(user_command, argv, env_scap, getcommand, pa_v, n);
				if (n == 0)
					free(user_command[0]);
			}
			free(user_command);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(_out_);
		}
		free(getcommand);
	}
	return (_out_);
}
