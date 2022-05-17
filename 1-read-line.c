#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - waits for user command and prints back the command
 *
 * Return: 0
 */
int main(void)
{
	char *buf, **argv, *token;
	size_t bufsize = 16;
	size_t argc, chars;

	buf = (char *)malloc(bufsize);

	if (buf == NULL)
	{
		printf("failed to allocate buf\n");
		return(98);
	}
	
	printf("$ ");
	chars = getline(&buf, &bufsize, stdin);

	printf("chars: %lu\n", chars);
	printf("bufsize: %lu\n", bufsize);
	printf("buf size: %lu\n", strlen(buf));
	printf("bufsize(after): %lu\n", bufsize);
	printf("%s\n", buf);
	printf("sizeof(argv): %lu\n", sizeof(argv));

	argv = (char **)malloc((bufsize) * sizeof(argv));

	for (argc = 0; ; buf = NULL, argc++)
	{
		token = strtok(buf, ": ");
		if (token == NULL)
			break;
		argv[argc] = token;
	}
	
	while (argc)
	{
		printf("arg %ld: %s\n", argc, argv[argc - 1]);
		argc--;
	}

	printf("\nstrlen: %lu\n", strlen(*argv));
	printf("sizeof: %lu\n", sizeof(*argv));

	free(buf);
	free(argv);
	return (0);
}

