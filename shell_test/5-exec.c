#include <stdio.h>
#include <unistd.h>

/**
 *  main - Exceve example
 *
 *  Return: always 0
 */ 

int main (void)
{
	char *argv[] = {"/bin/ls", "-l", NULL};
	extern char **environ;

	int val = execve(argv[0], argv, environ);

	if (val == -1)
		perror("Error:");

	printf("Done with execve");

	return (val);  

}


