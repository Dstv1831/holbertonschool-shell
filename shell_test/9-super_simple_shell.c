#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 *  main - write a first version of a super simple shell
 *  that can run commands with their full path, without any argument. 
 *
 *  Return: always 0
 */

char*  read_line(void)
{
	char *line_ptr = NULL;
	size_t len = 0;

	printf("#DSTV$ ");
	getline(&line_ptr, &len, stdin);
	line_ptr[strcspn(line_ptr, "\n")] = '\0'; // this line finds the index of the '\n' and replace it with '\0'

	return(line_ptr);

	//dont forget to free the allocated memory on line_ptr
}


int main(void)
{
	pid_t child;
	int status;

	extern char **environ;
	
	int val;
	bool shell = true;

	while (shell)
	{
		char *input = read_line();
		char *argv[] = {input, NULL};

		child = fork();
		if (child == -1)
		{
			perror("Error: Child aborted\n");
			free(input);
			return (1);		
		}
		if (child == 0)
		{
			val = execve(argv[0], argv, environ);
			if (val == -1)
				perror("Error: Skilless child ");
			free(input);
			printf("Task Done");
			return (0);
		}
		else
			wait(&status);
	}
	
	printf("Parent suicide\n");
	return (0);
}

