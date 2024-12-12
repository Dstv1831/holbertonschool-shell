#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * main - sets an environment variable
 *
 * Return: Always 0.
 */

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
	size_t name_len = strlen(name);
	size_t value_len = strlen(value);
	size_t total_len = name_len + value_len + 2;
	size_t env_count = 0;

	char *new_var;
	char **env = environ;
	char **new_environ;


	new_var = malloc(total_len);
	if (new_var == NULL)
	{
		perror("Memory allocation failed");
		return (-1);
	}

	sprintf(new_var, "%s=%s", name, value);

	while (environ[env_count] != NULL)
		env_count++;

	for (; *env != NULL; env++)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			if (overwrite != 0)
			{
				free(*env);
				*env = new_var;
				printf("Replaced");
				return (0);
			}
			else
			{
				free(new_var);
				printf("Exist");
				return (0);
			}
		}
	}
	
	new_environ = malloc((env_count + 2) * sizeof(char *));
	
	if (new_environ == NULL)
	{
		perror("Meomory alocation failed");
		free(new_var);
		return (-1);
	}
	for (int i = 0; i < env_count; i++)
		new_environ[i] = environ[i];

	new_environ[env_count] = new_var;
	new_environ[env_count + 1] = NULL;
	environ = new_environ;

	for (char **env2 = environ; *env2 != NULL; env2++)
	{
		printf("%s\n", *env2);
	}
	

	return (0);
}

int main(void)
{
	_setenv ("Chizuka", "Maekawa", 1);
	return (0);
}
