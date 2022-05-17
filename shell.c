#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *
 *
 *
 *
 *
 *
 */
int main(void)
{
	pid_t pid;
	int status, i;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		
		if (pid == -1)
		{
			dprintf(3, "Error: Could not create Child process");
			return(98);
		}

		if (pid == 0)
		{
			printf("Child Process: %u", getpid());
			execve(argv[0], argv, NULL);
		}

		else
		{
			wait(&status);
			printf("Parent Process: %u\n\n", getpid());
		}
	}

}
