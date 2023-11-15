#include "shell.h"
/**
 * execute_command - Loads and executes a new process
 * @command: Command to be executed in the new process
 * Return: 0 on success
*/

void execute_command(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid < 0)
	{
		perror("fork");
		exit(1);
	}

	else if (child_pid == 0)
	{
		char *args[2];

		args[0] = strdup(command);
		args[1] = NULL;

		execve(command, args, NULL);
		perror("execve");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}
