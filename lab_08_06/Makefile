SRC = ./src/
INCS = $(wildcard ./inc/*.h)
UNIT_SRC = ./unit_tests/src/
UNIT_INCS = $(wildcard ./unit_tests/inc/*.h)
OUT = ./out/
OBJS = $(OUT)memory_work.o $(OUT)io.o $(OUT)matrix_conversion.o $(OUT)multiplication.o
OBJS_UNIT = $(OUT)check_main.o $(OUT)check_multiplication.o $(OUT)check_matrix_conversion.o

CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wvla -pedantic -ggdb

.PHONY: clean unit debug release

clean:
	rm -f $(OUT)*.o *.exe

release: CFLAGS += -DNDEBUG -g0
release: app.exe

debug: CFLAGS += -g3
debug: app.exe

app.exe: $(OUT)main.o $(OBJS)
	$(CC) -o $@ $^

unit: unit_tests.exe
	./unit_tests.exe

unit_tests.exe: $(OUT)check_main.o $(OBJS) $(OBJS_UNIT)
	$(CC) -o $@ $^ -lcheck

$(OUT)%.o: $(SRC)%.c $(INCS)
	cd out && $(CC) $(CFLAGS) -I "../inc/" -c ../$<

$(OUT)%.o: $(UNIT_SRC)%.c $(UNIT_INCS)
	cd out && $(CC) $(CFLAGS) -I "../unit_test/inc/" -c ../$<