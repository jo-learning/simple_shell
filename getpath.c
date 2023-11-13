#include "shell.h"
/**
* _getpath - simple shell main function
* @command: commands
* Return: 0 Always (success)
*/
char *_getpath(char *command)
{
	char *path, *cmd, *dir;
	struct stat st;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (strdup_cus(command));
			return (NULL);
		}
	}

	path = _getenv("PATH");
	dir = strtok(path, ":");
	while (dir)
	{
		cmd = malloc(strlen_cus(dir) + strlen_cus(command) + 2);
		if (cmd)
		{
			strcpy_cus(cmd, dir);
			strcat_cus(cmd, "/");
			strcat_cus(cmd, command);
			if (stat(cmd, &st) == 0)
			{
				free(path);
				return (cmd);
			}
			free(cmd), cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path);
	return (NULL);
}
