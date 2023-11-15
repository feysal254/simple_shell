#include "shell.h"
/**
 * tokenize_command - Splits a string into tokens
 * @command: String to be split
 * Return: 0 on success
*/

void tokenize_command(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(1);
	}

	else if (child_pid == 0)
	{
		char *args[120];
		int args_count = 0;
		char *token = strtok((char *)command, " ");
		char *envp[] = {NULL, NULL};

		while (*token && args_count < 119)
		{
			args[args_count] = token;
			args_count++;
			token = strtok(NULL, " ");
		}

		args[args_count] = NULL;

		execve(args[0], args, envp);
		perror("execve");
		exit(1);
	}

	else
	{
		wait(NULL);
	}
}
