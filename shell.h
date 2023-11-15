#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"
extern char **environ;

char *readLine(void);
char *strdup_cus(const char *str);
int strcmp_cus(char *p1, char *p2);
int strlen_cus(char *s);
char *strcat_cus(char *dest, char *src);
char **tokenizer(char *line);
void freearray(char **arr);
int execute_cus(char **command, char **argv, int idx);
char *_getenv(char *variable);
char *_getpath(char *command);
void printerror(char *name, char *cmd, int idx);
char *_itoa(int n);
void reverse_string(char *str, int len);
char *strcpy_cus(char *dest, char *src);
int is_builtin(char *command);
void handle_builtin(char **command, int status);
void exit_shell (char **command, int status);
void print_env(char **command);



#endif
