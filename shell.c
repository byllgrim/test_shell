#include <errno.h>
#include <stdio.h> /* TODO remove */
#include <stdlib.h>
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
shell_populatearg(char *str, int argc, struct arg *arg)
{
	int i, tmp;
	char *tok;

	strtok(str, " "); /* TODO \n \t etc */

	for (i = 0; i < argc; i++) {
		errno = 0; /* TODO errno ^= errno */
		tok = strtok(NULL, " ");
		if (!tok) {
			fprintf(stderr, "too few arguments\n");
			return; /* TODO return ERROR */
			/* TODO remove duplication */
		}

		tmp = strtol(tok, NULL, 10); /* TODO other blanks */
		if (errno) {
			fprintf(stderr, "error argument\n");
			return; /* TODO return ERROR */
		}

		*(int*)((char *)arg + i*sizeof(arg->a1)) = tmp;
			/* TODO ^ proper structure */
	}
}

int
shell_parse(char *str)
{
	struct command *cmd;
	struct arg arg = {0};

	str[strlen(str) - 1] = '\0'; /* TODO remove? */
	cmd = shell_findcommand(str);
	if (!cmd) {
		fprintf(stderr, "no such command\n");
		return ERROR;
	}

	shell_populatearg(str, cmd->argc, &arg);
	return cmd->func(&arg);
}
