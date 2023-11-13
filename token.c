#include "shell.h"
/**
* tokenizer - simple shell main function
* @line: count of arguments
* Return: 0 Always (success)
*/

char **tokenizer(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int c = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = strdup_cus(line);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		c++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	command = malloc(sizeof(char *) * (c + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}

	token = strtok(line, DELIM);
	while (token)
	{
		command[i] = strdup_cus(token);
		i++;
		token = strtok(NULL, DELIM);
	}
	free(line), line = NULL;
	command[i] = NULL;
	return (command);

}
