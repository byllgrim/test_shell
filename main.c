#include <stdio.h>

#include "shell.h"

int
main(void)
{
	char str[LINE_SIZE];

	while (1)
		shell_parse(fgets(str, LINE_SIZE, stdin));

	return 0;
}
