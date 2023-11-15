#include "header.h"

	char **commands = NULL;
	char *line = NULL;
	char *shell_name = NULL;
	int status = 0;

/**
 * main - entry point
 * @argc: arguments passed
 * @argv: arguments to be parsed
 * Return: 0 on success
 */


int main(int argc __attribute__((unused)), char **argv)
{
	char **current_cmd = NULL;
	int i, type_cmd = 0;
	size_t n = 0;

	signal(SIGINT, ctrl_c_handler);
	shell_name = argv[0];
	while (1)
	{
		non_interactive();
		print(" Simple_shell$ ", STDOUT_FILENO);
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
			remove_newline(line);
			remove_comment(line);
			commands = tokenizer(line, ";");

		for (i = 0; commands[i] != NULL; i++)
		{
			current_cmd = tokenizer(commands[i], " ");
			if (current_cmd[0] == NULL)
			{
				free(current_cmd);
				break;
			}
			type_cmd = parse_command(current_cmd[0]);

			/* initializer -   */
			initializer(current_cmd, type_cmd);
			free(current_cmd);
		}
		free(commands);
	}
	free(line);

	return (status);
}
