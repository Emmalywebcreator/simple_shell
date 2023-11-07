#include "s_shell.h"

/**
 * our print - use for printing to the standard input 
 */

void our_print(const char *format)
{
	write(STDOUT_FILENO, &format, strlen(format));
}
