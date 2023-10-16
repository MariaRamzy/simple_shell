#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
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

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
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

/* cd.c */
void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash);
int cd_shell(data_shell *datash);

/* get_builtin */
int (*get_builtin(char *cmd))(data_shell *datash);

#endif
