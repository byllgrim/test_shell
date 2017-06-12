static struct command commands[] = {
	/* name  argc callback */
	{"help", 0, test_help},
	{"exit", 0, test_exit},
	{"init", 3, test_init},
};
