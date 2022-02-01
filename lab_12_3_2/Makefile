CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic

library/lib_arr.so: library/lib_arr.c library/lib_arr.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ ./library/lib_arr.c

.PHONY: lib clean

lib: library/lib_arr.so

clean:
	rm -f ./library/*.so
