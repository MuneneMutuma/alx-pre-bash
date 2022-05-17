#include <stdio.h>

extern char **environ;

/**
 *
 *
 *
 *
 *
 *
 *
 */
int main (int argc, char **argv, char **env)
{
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("[%d]: %s\n", i, environ[i]);
		i++;
	}

	printf("env: %p\n", *env);
	printf("environ: %p\n", *environ);
	return(0);
}
