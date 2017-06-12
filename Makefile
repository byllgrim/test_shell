SRC = main.c shell.c tests.c #TODO alphabitized
OBJ = ${SRC:.c=.o}

test_shell: ${OBJ}
	${CC} -o $@ ${OBJ}

.o:
	${CC} -c $<

clean:
	rm test_shell *.o
