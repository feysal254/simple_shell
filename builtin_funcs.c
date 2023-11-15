#include "shell.h"
/**
 * my_exit - Exits the shell
 * @info: Structure containing arguments
 * Return: Exits the shell with given exit status
*/
int my_exit(shell_info *info)
{
	int exit_status;

	if (info->argv[1])
	{
		exit_status = _atoi(info->argv[1]);

		if (exit_status == -1)
		{
			info->status = 2;
			write_error(info, "Invalid number: ");
			_puts(info->argv[1]);
			_putchar('\n');
			return (1);
		}
		info->err_num = _atoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
