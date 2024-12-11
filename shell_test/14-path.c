#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include "main.h"

/**
 * main - prints all directorys in PATH
 *
 * Return: Always 0.
 */

int main(void)
{
	char *path = _getenv("PATH");
	char *route;


		route = strtok(path, ":");
		while (route != NULL)
		{
           		printf(" %s\n", route);
        		route = strtok(NULL,":");
		}
    	return (0);
}
