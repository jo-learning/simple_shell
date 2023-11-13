#include "shell.h"
/**
* is_builtin - simple shell main function
* @command: command
* Return: 0 Always (success)
*/

int is_builtin(char *command)
{
	char *builtins[] = {"exit", "env", "setenv", "cd", NULL};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (strcmp_cus(command, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
* handle_builtin - simple shell main function
* @command: command
* @argv: argument
* @status: status
* @idx: index
* Return: 0 Always (success)
*/
void handle_builtin(char **command,  int status)
{
	if (strcmp_cus(command[0], "exit") == 0)
		exit_shell(command, status);
	else if (strcmp_cus(command[0], "env") == 0)
		print_env(command);
}
/**
* exit_shell - simple shell main function
* @command: command
* @status: status
* Return: 0 Always (success)
*/
void exit_shell(char **command, int status)
{
	freearray(command);
	exit(status);
}
/**
* print_env - simple shell main function
* @command: command
* @status: status
* Return: 0 Always (success)
*/
void print_env(char **command)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen_cus(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray(command);
}
