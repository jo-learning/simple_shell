#include "shell.h"
/**
* printerror - simple shell main function
* @name: name of the shell
* @cmd: command
* @idx: index
* Return: 0 Always (success)
*/

void printerror(char *name, char *cmd, int idx)
{
	char *index, msg[] = ": not found";

	index = _itoa(idx);
	write(STDERR_FILENO, name, strlen_cus(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, strlen_cus(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlen_cus(cmd));
	write(STDERR_FILENO, msg, strlen_cus(msg));
	free(index);
}

/**
* _itoa - simple shell main function
* @n: name of the shell
* Return: 0 Always (success)
*/
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_string(buffer, i);
	return (strdup_cus(buffer));
}
