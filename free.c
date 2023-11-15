#include "shell.h"
/**
* freearray - simple shell main function
* @arr: count of arguments
* Return: 0 Always (success)
*/

void freearray(char **arr)
{
	int i;

	if (!arr)
		return;
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr), arr = NULL;
}
