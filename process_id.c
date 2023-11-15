#include "header.h"

/**
 * initializer - executes everything
 * @current_cmd: check current token
 * @type_cmd: parse token
 *
 * Return: void function
 */

void initializer(char **current_cmd, int type_cmd)
{
	pid_t PID;

	if (type_cmd == EXTERNAL_COMMAND || type_cmd == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
			execute_command(current_cmd, type_cmd);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		execute_command(current_cmd, type_cmd);
}
