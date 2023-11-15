#ifndef _SHELL_H
#define _SHELL_H


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_SIZE " \t\r\n\a" 

void print_environ(void);
int _strcmp(char *s1, char *s2);
char **parse_input_string(char *buffer);
char *path_search(char *cmd);
char *_strncat(char *dest, char *src, int n);
int string_length(char *pointer);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);

/* _exit.c */
int exit_shell(data_shell *datash);
#endif
