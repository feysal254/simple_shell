#include "shell.h"

/**
 * _exit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _exit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) 
	       	/* exit arguement */
	{
		exitcheck = _error tool(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "error: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _errortool(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

