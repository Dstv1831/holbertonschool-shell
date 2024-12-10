#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

/**
 * main - Find the PATH to a file
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	int i = 1;
	struct stat st;
	char *env_path = getenv("PATH");
	char *path, *full_path, *copy_env_path;

	while (i < ac)
    	{
		copy_env_path = strdup(env_path);
		printf("searching for %s\n", av[i]);
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
