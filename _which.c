#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"

int main(int argc, char **argv)
{
	char *path, **list, *token, *filename = '\0';
	size_t i;
	unsigned int k;
	struct stat st;

	path = getenv("PATH");
	list = (char **)malloc(strlen(path) * sizeof(list));

	for (i = 0; ; path = NULL, i++)
	{
		token = strtok(path, ": ");
		if (token == NULL)
			break;
		list[i] = token;
	}

	argc--;
	while(argc)
	{
		for(k = 0; list[k]; k++)
		{
			filename = realloc(filename, (strlen(list[k]) + strlen(argv[argc]) + 1) * sizeof(filename));
			strcat(filename, list[k]);
			strcat(filename, "/");
			strcat(filename, argv[argc]);
			if (stat(filename, &st) == 0)
			{
				printf("%s\n", filename);
				return (0);
			}
			memset(filename, '\0', 1);
		}
		argc--;
	}

	return (98);
}
