#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

ssize_t shell_prompt(char *buf, size_t n);
void our_print(const char *format);



#endif
