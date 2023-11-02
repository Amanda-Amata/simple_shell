#include "header.h"

/**
 * print_failure - prints error massege
 * @arg: massege to be printed
 * @argv: system process
 * Return: void
 */

void print_failure(char arg[], char argv[])
{
	char line_str[10];

	sprintf(line_str, "%d", __LINE__);
	write(STDERR_FILENO, argv, strlen(argv));
	write(STDERR_FILENO, ": 1: ", 5);
	write(STDERR_FILENO, line_str, strlen(line_str));
	write(STDERR_FILENO, arg, strlen(arg));
	write(STDERR_FILENO, ": Not found\n", 12);
}

/**
 * execute_prompt - execute command
 * @cmd: command to execute
 * @argv: system process
 * Return: void
 */

void execute_prompt(const char *cmd, char *argv)
{
	pid_t process_id = fork();
	char *args[MAX_ARGS / 2 + 1];
	int count = 0;
	char *token = strtok((char *)cmd, " ");

	if (strcmp(cmd, "exit") == 0)
		exit(EXIT_SUCCESS);

	if (process_id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	while (token != NULL && count < MAX_ARGS)
	{
		args[count] = token;
		count++;
		token = strtok(NULL, " ");
	}
	args[count] = NULL;
	if (process_id == 0)
	{
		while (token != NULL && count < MAX_COMMAND_LENGTH / 2)
		{
			args[count] = token;
			count++;
			token = strtok(NULL, " ");
		}
		args[count] = NULL;
		if (execve(args[0], args, NULL) == -1)
		{
			print_failure(args[0], argv);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}

/**
 * read_cmd - reads command from the user
 * @cmd: command to read
 * @size: size of command
 * Return: void
 */

void read_cmd(char *cmd, size_t size)
{
	if (fgets(cmd, size, stdin) == NULL)
	{
		exit(EXIT_SUCCESS);
	}
	cmd[strcspn(cmd, "\n")] = '\0';
}


