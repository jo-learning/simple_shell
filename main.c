#include "shell.h"
/**
* main - simple shell main function
* @argc: count of arguments
* @argv: Arguments
* Return: 0 Always (success)
*/

int main(int argc, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, idx = 0;
	(void) argc;

	while (1)
	{
		line = readLine();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		command = tokenizer(line);
		if (!command)
			continue;
		idx++;
		if (is_builtin(command[0]))
			handle_builtin(command, status);
		else
			status = execute_cus(command, argv, idx);
	}
}
