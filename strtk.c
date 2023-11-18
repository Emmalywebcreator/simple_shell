#include "main.h"


 void _strtok(const char *str, char delim)
{
	int len = _strlen((char*)str);
	int i, j;

	char *word = malloc(len + 1);
	if (word == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	
	for (i = 0; i < len; i++)
	{
		j = 0;
		if (str[i] == delim || str[i] == '\0')
		{
			word[j] = '\0';
			if (j > 0)
			{
				_printf("%s\n", word);

				j = 0;
			}
		}
		else
		{
			word[j++] = str[i];
		}

	}
	free(word);
}

