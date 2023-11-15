#include "shell.h"

/**
  * print_env - prints environment variables.
  * Return: nothing.
  */
void print_environ(void)
{
	int i;

	i = 0;
	while (environ[i])
		printf("%s\n", environ[i++]);
}
