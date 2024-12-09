#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  main - strtok function that splits strings
 *  @str: string to be splitted
 *  @del: delimiter of the strings
 *
 *  return: Array of each word of the string
 */ 

char** split (char* string, char* del)
{
	char *token;
	char **arr_str = NULL;
	int len = 0, i = 0, j = 0;
	// J is neccesarry to avoid freeing memory that is not yet allocated
	// with my condition of (i; i<len; i++) => WRONG
	//
	// for some reason is a pain in the... to work directly with the string 
	// so better to create a copy of that string (string_copy)
	// and use strtok with that copy to count the tokens.
	
	char *string_copy = strdup(string);

	if (string_copy == NULL)
	{
		puts("Failed to copy the String");
		return (NULL);
	}

	token = strtok(string_copy, del);
	while (token != NULL)
	{
		len++;
		token = strtok(NULL, del);
	}
	
	arr_str = malloc((len + 1) * sizeof(char*));
	
	if (arr_str == NULL)
	{
	       puts("Failed to allocate memory");
	       return (NULL);
	}

	token = strtok(string, del);
	while (token != NULL)
	{
		arr_str[i] = malloc((strlen(token) + 1) * sizeof(char));
		if (arr_str[i] == NULL)
		{
			puts("Failed to allocate memory");
			for (j = 0; j < i; j++)
				free(arr_str[j]);
			free(arr_str);
			return NULL;
		}
		strcpy(arr_str[i], token);
		token = strtok(NULL, del);
		i++;
	}

	arr_str[i] = NULL;
	return (arr_str);
}

int main(void) {
    char sen[35] = "David Santiago Tangarife Villamizar";
    char del[2] = " ";

    char **sentence = split(sen, del);

        for (int i = 0; sentence[i] != NULL; i++)
            printf("word %d: %s\n", i + 1, sentence[i]);
    return 0;
}


