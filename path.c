#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * path_finder - a function that check if a command is valid
 * @com: the command
 *
 * Return 0 on success
 * 1: on failure
 */



char *path_finder(char *com)
{
	char *path = getenv("PATH");
	char *token;
	int com_len, path_len;
	char *p = strdup(path);

	token = strtok(p, ":");
	while(token != NULL)
	{
		com_len = strlen(com);	
		path_len = strlen(token);
		char *command = malloc(com_len + path_len + 2);

		if (!command)
		{
			free(p);
			return(NULL);
		}

		strcpy(command, token);
		strcat(command, "/");
		strcat(command, com);
		if (access(command, X_OK) == 0)
		{

			free(p);
			return (command);
		}
		free(command);
		token = strtok(NULL, ":");
	}
	free(p);
	return (NULL);
}

