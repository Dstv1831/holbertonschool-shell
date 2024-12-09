#include <stdio.h>
#include <stdlib.h>

/**
 * main - Read Line
 *
 * Return - Always 0. 
 */

int main (void)
{
	char *line_ptr = NULL;
	size_t len = 0;
	
	printf("$ ");
	getline(&line_ptr, &len, stdin);
	printf("%s\n", line_ptr);
	free(line_ptr);
	return (0);
}
