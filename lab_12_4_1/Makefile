SRC = ./src/
INCS = $(wildcard ./inc/*.h)
UNIT_SRC = ./unit_tests/src/
UNIT_INCS = $(wildcard ./unit_tests/inc/*.h)
OUT = ./out/
OBJS = $(OUT)filter_file.o $(OUT)io_file.o $(OUT)sort_file.o
OBJS_UNIT = $(OUT)check_main.o $(OUT)check_io_file.o $(OUT)check_filter_file.o $(OUT)check_sort_file.o
DYNAMIC_LIB = $(OUT)libarr.so
STATIC_LIB = $(OUT)libarr.a

CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wvla -pedantic

.PHONY: clean unit debug release compile_static compile_dynamic clean_libs

release: CFLAGS += -DNDEBUG -g0
release: app.exe

debug: CFLAGS += -g3
debug: app.exe

$(DYNAMIC_LIB): $(OBJS)
	$(CC) -o $@ -shared $^
	#$(CC) -shared $^ -Wl,--subsystem,windows -o $@

$(STATIC_LIB): $(OBJS)
	ar cr $@ $^
	ranlib $@

compile_static: $(OUT)main.o $(STATIC_LIB)
	$(CC) -o app.exe $(OUT)main.o -L $(OUT) -larr

compile_dynamic: $(DYNAMIC_LIB)

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

clean:
	rm -f $(OUT)*.o *.exe

clean_libs:
	rm -rf $(OUT)*.a $(OUT)*.so *.a *.so