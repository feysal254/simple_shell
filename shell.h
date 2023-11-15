#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* buffers */
#define BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLASH -1

/**
 * struct info - Contains all the arguments needed
 * @argv: Array of arguments
 * @file_name: Name of the file
 * @line_count: Line error occurs
 * @err_num: Error code
 * @status: Status of the last executed command
*/
typedef struct info
{
	char **argv;
	char *file_name;
	unsigned long int line_count;
	int status;
	int err_num;
} shell_info;

/*simple_shell*/
void display_prompt(void);
void user_input(char *command, size_t size);
void execute_command(const char *command);
int print_output(const char *buff);
void tokenize_command(const char *command);

/* builtin_funs */
int my_exit(shell_info *info);


/* errors */
int _atoi(char *s);
void write_error(shell_info *info, char *msg);
int print_integer(int input, int fd);
void _puts(char *s);
int _putchar(char c);

#endif
