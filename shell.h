#include <stdint.h>

enum {
	OK = 0,
	ERROR = 1,
	LINE_SIZE = 128,
};

struct arg {
	int a1;
	int a2;
	int a3;
};

struct command {
	char *name;
	uint8_t argc;
	uint8_t (*func)(struct arg *);
};

int shell_parse(char *str);
