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
void execute_command_using_path(char *command, char *args[], char *envp[]);
int _write_string(const char *str);
int _write_percent(void);
int _write_integer(int n);
int _printf(const char *format, ...);
char *custom_getline(void);
int execute_command(char *command);
ssize_t user_input(char *buf, size_t n);
void our_print(const char *format);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void display_prompt();
void handle_exit_command(char *command);
char *_strtok(char *str, const char *delim);
#endif
