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

uint8_t
test_init(struct arg *arg)
{
	printf("init N=%d M=%d X=%d\n", arg->a1, arg->a2, arg->a3);
	/* TODO implement */

	return OK;
}
