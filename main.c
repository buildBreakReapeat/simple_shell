#include "main.h"

/**
 * main - Recreation of a "sh"
 *@ac: count cmd line args
*@av: array of user defined cmds
 * Return: 0 If succeed, or the number of the error
 */
int main(int ac, char **av)
{
	size_t i = 0;
	int buffsize = 0, builtIn = 0, status = 0, exitValue = 0, child_pid = 0;
	char *buffer = NULL, **argv = NULL, *dup = NULL;

	while (1)
	{
		signal_isatty();
		buffsize = _getline(&buffer, &i, stdin);
		if (buffsize == -1)
			free_and_exit(buffer);
		if (is_str(buffer) == -1)
			continue;
		buffer = trim_buff(buffer, buffsize);
		builtIn = _checkBuiltIn(buffer);
		if (builtIn == 1)
		{
			exitValue = getReturnValue(buffer);
			if (exitValue >= 0)
				break;
			continue;
		}
		dup = _strdup(buffer);
		argv = tokenize(dup, builtIn);
		if ((builtIn == 0 && itsExecutable(argv[0], ac, av[0]) == 0))
			child_pid = child_fork(child_pid, argv[0]);
		else
			child_pid = 1;
		if (child_pid == 0 && execve(argv[0], argv, environ) == -1)
		{
			perror(argv[0]);
			break;
		}
		if (child_pid != 0)
			wait_free(status, argv, dup);
	}
	if (builtIn != 1)
		free_array_dup(argv, dup);
	free(buffer);
	return (exitValue);
}
