#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 *
 *
 *
 *
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buf, *line;
	char delim = '\n';
	int fd0, fd;
	ssize_t len = 0;

	buf = malloc(32);
	line = malloc(*n);
	line[0] = '\0';

	fd0 = fileno(stream);
	fd = dup(fd0);
	close(fd0);
	do {
		read(fd, buf, 32);
		if (*n - strlen(line) < 32)
		{
			line = realloc(line, *n * 2);
			*n *= 2;
		}
		strcat(line, buf);
		memset(buf, '\0', 32);
	} while (line[strlen(line) - 1] != delim);


	if (strlen(line) != *n -1)
	{
		line = realloc(line, strlen(line) + 1);
	}

	*lineptr = strdup(line);
	*n = strlen(*lineptr);
	free(line);
	free(buf);
	return (len);
}
