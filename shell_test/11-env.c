#include <stdio.h>
#include <unistd.h>

/**
 * main - Prints the variable ENVIRON
 *
 * Return: Always 0.
 */

int main(void)
{
	extern char **environ;
	int i = 0;

	while(environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
