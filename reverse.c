#include "shell.h"
/**
* reverse_string - simple shell main function
* @str: strings
* @len: length
* Return: 0 Always (success)
*/
void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
