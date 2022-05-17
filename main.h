#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

ssize_t _getline(char **lineptr, size_t *n , FILE *stream);
size_t split_to_av(char ***argv, char **str, size_t *bufsize);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);

#endif	
