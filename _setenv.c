#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

extern char **environ;


int _setenv(const char *name, const char *value, int overwrite)
{
	char *newenv, *test, *buf, *token;
	int i;
	size_t len;

	len = (strlen(name) + strlen(value) + 3);
	newenv = malloc(len);
	memset(newenv, '\0', len);
	buf = malloc(16);

	test = _getenv(name);

	strcat(newenv, strdup(name));
	strcat(newenv, "=");
	strcat(newenv, strdup(value));
	
	printf("%s\n", environ[0]);
	if (test && overwrite)
	{
		for (i = 0; environ[i]; i++)
		{
			
			buf = strdup(environ[i]);
			token = strtok(buf, "=");
			if (strcmp(token, name) == 0)
			{
				printf("token: %s\n", token);
				printf("test: %s\n", test);
				printf("name: %s\n",name);
				printf("value: %s\n", value);
				environ[i] = strdup(newenv);
				printf("environ[%d]: %s\n", i, environ[i]);	
			}
		}
	}

	printf("envrion[0]: %s\n", environ[0]);
	newenv = _getenv(name);
	printf("newnv: %s\n", newenv);


	if (!test)
	{
		environ[i] = newenv;
		printf("%s\n", environ[i]);
		return (99);
	}
	
	return (0);
}
