#include "shell.h"
/**
* _getenv - simple shell main function
* @variable: variable that is in env
* Return: 0 Always (success)
*/

char *_getenv(char *variable)
{
	char *tmp, *key, *value, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = strdup_cus(environ[i]);
		key = strtok(tmp, "=");
		if (strcmp_cus(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = strdup_cus(value);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
