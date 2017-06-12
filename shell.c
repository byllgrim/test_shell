#include <stdio.h> /* TODO remove */
#include <string.h> /* TODO remove */

#include "shell.h"
#include "tests.h"

#include "config.h" /* included last */

static struct command *
shell_findcommand(char *str)
{
	int i, len;

	len = sizeof(commands) / sizeof(commands[0]);
	for (i = 0; i < len; i++)
		if (!strncmp(str, commands[i].name, LINE_SIZE - 1))
			return &commands[i];

	return (void *)0;
}

int
shell_parse(char *str)
{
	struct command *cmd;

	str[strlen(str) - 1] = '\0'; /* TODO remove? */
	cmd = shell_findcommand(str);
	if (!cmd) {
		fprintf(stderr, "no such command\n");
		return ERROR;
	}

	cmd->func((void *)0);

	return 0;
}
