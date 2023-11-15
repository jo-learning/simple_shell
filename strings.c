#include "shell.h"
/**
* strdup_cus - simple shell main function
* @str: String
* Return: 0 Always (success)
*/

char *strdup_cus(const char *str)
{
	char *p;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		p[i] = str[i];
	return (p);
}

/**
* strcmp_cus - simple shell main function
* @p1: count of arguments
* @p2: Arguments
* Return: 0 Always (success)
*/
int strcmp_cus(char *p1, char *p2)
{
	int cmp;

	cmp = (int)*p1 - (int)*p2;
	while (*p1)
	{
		if (*p1 != *p2)
			break;
		p1++;
		p2++;
		cmp = (int)*p1 - (int)*p2;
	}
	return (cmp);
}
/**
* strlen_cus - simple shell main function
* @s: count of arguments
* Return: 0 Always (success)
*/

int strlen_cus(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}
/**
* strcat_cus - simple shell main function
* @dest: count of arguments
* @src: Arguments
* Return: 0 Always (success)
*/

char *strcat_cus(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;
	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = *src;
	return (dest);
}
/**
* strcpy_cus - simple shell main function
* @dest: count of arguments
* @src: Arguments
* Return: 0 Always (success)
*/
char *strcpy_cus(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
