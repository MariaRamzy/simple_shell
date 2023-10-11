#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

int _putchar(char);

/* enviroment1.c */
char *_getenv(const char *name, char **_environ);
int _env(data_shell *datash);

/* enviroment2.c */
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);

#endif
