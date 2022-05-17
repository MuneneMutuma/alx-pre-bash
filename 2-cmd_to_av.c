#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * split_to_av - splits input string to tokens in to av
 *
 * @str: string to be split
 *
 * Return: array of pointers to the tokens
 */
size_t split_to_av(char ***argv, char **str, size_t *bufsize)
{
	char *delim = " \n";
	char *token, *buf, **arg_buf;
	size_t argc = 0, i;

	arg_buf = malloc(*bufsize);

	if (*argv == NULL)
		return(98);


	for (buf = strdup(*str); token != NULL ; buf = NULL, argc++, arg_buf++)
	{
		token = strtok(buf, delim);
		printf("%lu", strlen(token));
		printf("%s\n", token);

		if (token == NULL)
			break;

		*arg_buf = strdup(token);
	}

	for (i = 0; arg_buf[i]; i++)
		printf("%s\n", arg_buf[i]);

	**argv = strdup(*arg_buf);
	free(arg_buf);

	return (argc);
}
