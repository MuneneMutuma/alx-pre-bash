#include "main.h"
#include <stdlib.h>
#include <stdio.h>


int main(int ac, char **av)
{
	char *value;

	for (int i = 1; av[i] && i < ac; i++)
	{
		value = _getenv(av[i]);
		printf("%s=", av[i]);
		printf("%s\n", value);
	}
	return (0);
}
