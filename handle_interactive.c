#include "header.h"

/**
 * non_interactive - handles non_interactive mode
 *
 * Return: void
 */

void non_interactive(void)
{
	char **current_cmd = NULL;
	int i, type_cmd = 0;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&line, &n, stdin) != -1)
		{
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
				initializer(current_cmd, type_cmd);
				free(current_cmd);
			}
			free(commands);
		}
		free(line);
		exit(status);
	}
}
