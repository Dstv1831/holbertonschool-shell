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
	char *path = get_env("PATH");

		path = strtok(copy_env_path, ":");
		while (path != NULL)
		{
			full_path = malloc(strlen(path) + strlen(av[i]) + 2);
			sprintf(full_path, "%s/%s", path, av[i]);	
        		if (stat(full_path, &st) == 0)
           			printf("Found in %s\n", full_path);
        		else
				printf("NOT FOUND\n");
        		path = strtok(NULL,":");
		}
		i++;
    	}
    	return (0);
}
