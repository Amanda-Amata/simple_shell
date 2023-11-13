#include "header.h"

/**
 * env - function that implements env built in
 * Return: 0 on success and -1 of error
 */

void env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env++);
	}
}
