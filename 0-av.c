#include <stdio.h>

/**
 * main - prints arguements of the program
 *
 * Return: 0 always.
 */
int main(int argc, char **argv)
{
	int i;

	i = 0;
	while(argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
