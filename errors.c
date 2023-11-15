#include "shell.h"
/**
 * _atoi - Converts a string to an integer
 * @s: String to be converted
 * Return: 0 on success, otherwise -1
*/
int _atoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (s != NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			if (s[i] < '0' || s[i] > '9')
				return (-1);
		}
		result *= 10;
		result += s[i] - '0';
	}
	return (result);
}

/**
 * write_error - Prints an error message
 * @info: Structure containing arguments
 * @msg: Message containing specific error type
 * Return: 0 on success
 */
void write_error(shell_info *info, char *msg)
{
	_puts(info->file_name);
	_puts(": ");
	print_integer(info->line_count, STDERR_FILENO);
	_puts(": ");
	_puts(info->argv[0]);
	_puts(": ");
	_puts(msg);
}

/**
 * print_integer - Prints an integer number
 * @input: The input
 * @fd: File descriptor to write to
 * Return: Number of characters printed
*/
int print_integer(int input, int fd)
{
	int count = 0;

	if (fd == STDERR_FILENO)
		fd == _fileno(stderr);

	if (input < 0)
	{
		fputc('-', fd);
		count++;
	}

	unsigned int _abs_ = input >= 0 ? input : -input;

	while (_abs_)
	{
		fputc('0' + _abs_ % 10, fd);
		count++;
		_abs_ /= 10;
	}

	return (count);
}

/**
 * _puts - Prints an input string
 * @str: String to be printed
*/
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - Writes character c to the standard output
 * @c: Character to be printed
 * Return: 1 on sucess
 */
int _putchar(char c)
{
	static int i;
	static char buf[BUF_SIZE];

	if (i == BUF_SIZE || c == '\0')
	{
		write(2, buf, i);
		i = 0;
	}

	if (c != '\0')
	{
		buf[i++] = c;
	}
	return (1);
}
