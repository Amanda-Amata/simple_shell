#include "header.h"

void execute_prompt(const char *cmd, char *argv);
void read_cmd(char *cmd, size_t size);

/**
 * main - entry point
 * @arg: process value
 * @argv: process status
 * Return: always 0
 */

int main(int arg, char *argv[])
{
	char cmd[140];

	if (arg == 0)
		return (0);

	while (1)
	{
		show_prompt();
		read_cmd(cmd, sizeof(cmd));
		execute_prompt(cmd, argv[0]);
		fgets(cmd, sizeof(cmd), stdin);
		cmd[strcspn(cmd, "\n")] = '\0';
		if (strcmp(cmd, "env") == 0)
		{
			env();
		}
	}
	return (0);
}
