SRC = ./src/
INCS = $(wildcard ./inc/*.h)
UNIT_SRC = ./unit_tests/src/
UNIT_INCS = $(wildcard ./unit_tests/inc/*.h)
OUT = ./out/
OBJS = $(OUT)my_snprintf.o
OBJS_UNIT = $(OUT)check_main.o $(OUT)check_my_snprintf.o

CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wvla -pedantic -ggdb

.PHONY: clean unit debug release

release: CFLAGS += -DNDEBUG -g0
release: app.exe

debug: CFLAGS += -g3
debug: app.exe

clean:
	rm -f $(OUT)*.o *.exe

app.exe: $(OUT)main.o $(OBJS)
	$(CC) -o $@ $^

unit: unit_tests.exe
	./unit_tests.exe

unit_tests.exe: $(OBJS) $(OBJS_UNIT)
	$(CC) -o $@ $^ -lcheck

$(OUT)%.o: $(SRC)%.c $(INCS)
	cd out && $(CC) $(CFLAGS) -I "../inc/" -c ../$<

$(OUT)%.o: $(UNIT_SRC)%.c $(UNIT_INCS)
	cd out && $(CC) $(CFLAGS) -I "../unit_test/inc/" -c ../$<