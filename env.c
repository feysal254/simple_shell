#include "shell.h"

/**
 * _myenv - prints the current environment
 *           function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}