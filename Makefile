SRC = main.c shell.c tests.c #TODO alphabitized
OBJ = ${SRC:.c=.o}

shell_test: ${OBJ}
	${CC} -o $@ ${OBJ}

.o:
	${CC} -c $<

clean:
	rm shell_test *.o
