#include "shell.h"
/**
 * main - Entry point of the shell
 * Return: 0 on success
*/

int main(void)
{
	char command[120];

	while (1)
	{
		display_prompt();
		user_input(command, sizeof(command));
		execute_command(command);
		tokenize_command(command);
	}

	return (0);
}
