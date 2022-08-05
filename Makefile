.PHONY = clean

CFLAGS = -I.
DEPS = common.h print_error.c
CC = gcc

%.o: ${DEPS} %.c
	${CC} $^ -o $@ ${CFLAGS}

launch_%: %.o
	./$^

clean:
	@echo "Cleaning up..."
	rm -rvf *.o
