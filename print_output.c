#include "shell.h"
/**
 * print_output - Prints the output to the screen
 * @buff: Pointer to the buffer containing data to be printed
 * Return: Number of bytes printed
*/

int print_output(const char *buff)
{
	return (write(1, buff, strlen(buff)));
}
