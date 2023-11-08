#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
int _write_char(char c);
int _write_string(const char *str);
int _write_percent(void);
int _write_integer(int n);
int _printf(const char *format, ...);
int execute_command(const char *command);
ssize_t shell_prompt(char *buf, size_t n);
void our_print(const char *format);



#endif
