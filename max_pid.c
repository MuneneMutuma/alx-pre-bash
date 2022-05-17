#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * main - prints pid_max
 *
 * Return: 0 always.
 */
int main(void)
{
	char *val;
	int fd;
	
	val = malloc(64);
	fd = open("/proc/sys/kernel/pid_max", O_RDONLY);
	read(fd, val, 64);

	printf("%s", val);
	free(val);

	return (0);
}
