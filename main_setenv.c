#include "main.h"
#include <stdio.h>

int main(void)
{
	int i = -2;

	i = _setenv("SHELL", "Emason", 2);

	printf("%d\n", i);
	return (1);
}
