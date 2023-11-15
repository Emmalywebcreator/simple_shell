#include "main.h"

int execute_command(char *input)
{
	char *token, *delim = " ";
	char *input_dup;
	char *args[50]; 
	char *envp[] = { NULL };
	int i;

	input_dup = strdup(input);
	if (input_dup == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	i = 0;
	token = strtok(input_dup, delim);
	while (token != NULL && i < 49)
	{
		args[i++] = token;
		_printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	args[i] = NULL;
	
	execute_command_using_path(args[0], args, envp);

	free(input_dup);

	return (0);
}

