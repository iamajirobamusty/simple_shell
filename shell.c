#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

/**
 * main - main entry
 * @ac: number of arguments passed
 * @av: list of arguments passed
 *
 * Return: 0 on success. 
 * On error: Any other number
 */
int main(int ac, char **av)
{
	int rd;
	char buffer[1024] = {0};
	char *argv[2];
	pid_t pid;

	if(!(isatty(STDIN_FILENO)))
	{
		rd = read(fileno(stdin), buffer, sizeof(buffer));
		if(rd == -1)
			perror("");
		if (rd == 0)
			exit(0);
		argv[0] = buffer;
		argv[1] = NULL;

		if (buffer[rd - 1] == '\n')
			buffer[rd - 1] = '\0';
		if(execve(argv[0], argv, NULL) == -1)
		{
			perror("./shell");
			exit(0);
		}
	}
	while(1)
	{
		pid = fork();

		if (pid == 0)
		{
			write(1, "#cisfun$ ", 9);
			rd = read(fileno(stdin), buffer, sizeof(buffer));
			if (buffer[rd - 1] == '\n')
				buffer[rd - 1] = '\0';
			if (rd == -1)
				perror("");
			size_t len = strlen(buffer);
			char *args[64];
			int i = 0;
			char *dup = malloc(len + 1);
			if (dup == NULL)
			{
				perror("Malloc");
				exit(1);
			}
			strcpy(dup, buffer);
			char *token = strtok(dup, " \t\n");
			while (token != NULL)
			{
				args[i++] = token;
				token = strtok(NULL, " \t\n");
			}
			args[i] = NULL;
			if (execve(args[0], args, NULL) == -1)
				perror("./shell");
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
