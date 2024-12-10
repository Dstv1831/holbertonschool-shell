#include <stdio.h>
#include <unistd.h>

/**
 * main - Prints the variable ENVIRON
 *
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	extern char **environ;

	printf("%p\n", (void *)env);
	printf("%p\n", (void *)environ);

	return (0);
}
