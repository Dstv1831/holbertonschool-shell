#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * unsetenv - unsets an environment variable
 *
 * Return: Always 0.
 */

extern char **environ;


int _unsetenv(const char *name)
{
	size_t name_len = strlen(name);

	char **env = environ;
	char **write_ptr;



	while (*env != NULL)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			env++;
			continue;
		}

		*write_ptr = *env;
		write_ptr++;
		env++;
	}

	*write_ptr = NULL;
	return (0);
}
