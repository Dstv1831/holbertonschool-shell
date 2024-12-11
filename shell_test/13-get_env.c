#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * main - gets an environment variable
 *
 * Return: Always 0.
 */

char *_getenv(const char *name) 
{
	extern char **environ;
	size_t len = strlen(name);
	
	if (name == NULL || *name == '\0')
		return (NULL);


	while (*environ)
	{
		// comparing two strings up until a certain character
		// also (*environ)[len] == '=' Treats the dereferenced string as a character array and accesses the character at index len
		// but (*environ) + len + 1: adds len + 1 to the pointer (*environ), shifting the pointer forward in memory. The resulting value is a pointer, not a character.
		if (strncmp(*environ, name, len) == 0 && (*environ)[len] == '=')
		{
			// vital to understand pointers arithmetic (adding to a pointer moves the position to which this one is point to)
			printf ("%s\n", (*environ + len + 1));
			return (*environ + len + 1);
		}
		environ++;
	}
	return(NULL);
}

int main(void)
{
	_getenv("PWD");
	return (0);
}
