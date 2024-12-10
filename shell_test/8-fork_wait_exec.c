#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 *  main - creates 5 child processes, each executing the command "ls -l /tmp". 
 *  The parent process should create one child at a time 
 *  and wait for the current child to exit before creating the next.
 *
 *  Return: always 0
 */

int main(void)
{
	pid_t parent;
	pid_t child;
	
	char message[15] = "Creating child";
	int i = 0;
	int status;

	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	extern char **environ;
	int val;

	parent = getpid();
	printf ("%u is the parent\n", parent);

	for (i = 0; i < 5; i++)
	{
		printf("%s\n", message);
		child = fork();
		
		if (child == -1)
		{
			perror("Error: Child aborted\n");
			return (1);		
		}
		
		if (child == 0)
		{
			printf("%u is the %d son\n", getpid(), i + 1 );
			sleep(1);
			val = execve(argv[0], argv, environ);
			if (val == -1)
				perror("Error: Skilless child ");
			printf("Task Done");			
			return (0); //is necessary for the child process to return or exit explicitly, as if it doesnt  it may continue running parent code after the if branch.
		}
		else
		{
			wait(&status);
			printf("Child terminated\n");
		}
	}
	printf("Parent suicide\n");
	return (0);
}

