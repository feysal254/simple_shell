#include "shell.h"
/**
 * user_input - Reads the user input
 * @command: Buffer that stores the input
 * @size: Number of bytes to read
 * Return: 0 on success
*/

void user_input(char *command, size_t size)
{
	int nbytes = read(0, command, size - 1);

	if (nbytes < 0)
	{
		perror("read");
		exit(0);
	}

	if (nbytes == 0)
	{
		exit(-1);
	}

	command[strcspn(command, "\n")] = '\0';
}
