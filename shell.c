#include <stdio.h> /* TODO remove */
#include <string.h> /* TODO remove */

#include "shell.h"
#include "tests.h"

#include "config.h" /* included last */

static struct command *
shell_findcommand(char *str)
{
	int i, n_cmds, len;

	n_cmds = sizeof(commands) / sizeof(commands[0]);
	len = strpbrk(str, " \t\n") - str; /* TODO other blanks */

	for (i = 0; i < n_cmds; i++)
		if (!strncmp(str, commands[i].name, len))
			return &commands[i];

	return (void *)0;
}

static void
shell_populatearg(char *str)
{
	printf("populate from %s\n", str);
	strtok(str, " "); /* TODO \n \t etc */
	printf("first arg %s\n", strtok(NULL, " "));
}

int
shell_parse(char *str)
{
	struct command *cmd;
	struct arg arg = {0};

	str[strlen(str) - 1] = '\0'; /* TODO remove? */
	printf("parse %s\n", str); /* TODO remove */
	cmd = shell_findcommand(str);
	printf("parse %s\n", str); /* TODO remove */
	if (!cmd) {
		fprintf(stderr, "no such command\n");
		return ERROR;
	}

	shell_populatearg(str);
	return cmd->func(&arg);
}
