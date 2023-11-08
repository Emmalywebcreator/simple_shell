#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
int _write_char(char c);
int _write_string(const char *str);
int _write_percent(void);
int _write_integer(int n);
int _printf(const char *format, ...);

#endif
