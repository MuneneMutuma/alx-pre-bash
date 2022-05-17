#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

char *_getenv(const char *name)
{
	char *buf, *token, *value;
	unsigned int i = 0;

	buf = malloc(16);
	value = "\0";
	while(environ[i])
	{
		buf = realloc(buf, strlen(environ[i]) * sizeof(buf));
		for (buf = environ[i]; ;buf = NULL)
		{
			token = strtok(buf, "=");
			if (token == NULL)
			{
				break;
			}
			if (strcmp(name, value) == 0)
			{
				value = strdup(token);
				free(buf);
				return(value);
			}
			if (strcmp(token, name) == 0)
			{
				value = strdup(token);
			}
		}
		i++;
	}
	free(buf);
	return(NULL);
}
