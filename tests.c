#include <stdio.h> /* TODO remove */
#include <stdlib.h> /* TODO remove */

#include "shell.h"

uint8_t
test_help(struct arg *arg)
{
	printf("This is a shell. TODO\n");

	return OK;
}

uint8_t
test_exit(struct arg *arg)
{
	exit(EXIT_SUCCESS);

	return OK; /* never reached TODO */
}
