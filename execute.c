#include "shell.h"
/**
* execute_cus - simple shell main function
* @command: count of arguments
* @argv: Arguments
* Return: 0 Always (success)
*/

int execute_cus(char **command, char **argv, int idx)
{
	char *cmd;
	pid_t child;
	int status;

	cmd = _getpath(command[0]);
	if (!cmd)
	{
		printerror(argv[0], command[0], idx);
		freearray(command);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(cmd, command, environ) == -1)
		{
			free(cmd), cmd = NULL;
			freearray(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearray(command);
		free(cmd), cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
