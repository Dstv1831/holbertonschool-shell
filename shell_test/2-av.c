#include <stdio.h>

/**
 * main - AV items
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	(void) ac;

	while (*av != NULL)
	{
		printf("%s\n", *av);
		av++;
	}

	return (0);
}
