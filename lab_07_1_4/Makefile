CC = gcc
INC = ./inc/
OUT = ./out/
SRC = ./src/
UNIT = ./unit_tests/
UNIT_INC = ./unit_tests/inc/
UNIT_SRC = ./unit_tests/src/
CMP_TIME = ./time_analysis/

CFLAGS = -std=c99 -Wall -Werror -Wvla -pedantic

OBJS = $(OUT)filter_file.o $(OUT)io_file.o $(OUT)sort_file.o

OBJS_UNIT = $(OUT)check_io_file.o $(OUT)check_filter_file.o $(OUT)check_sort_file.o

.PHONY : clean debug release

clean:
	$(RM) $(OUT)*.o *.exe $(CMP_TIME)*.txt

release: CFLAGS += -DNDEBUG -g0
release: app.exe

debug: CFLAGS += -g3
debug: app.exe

unit: unit_tests.exe
	./unit_tests.exe

cmp_time: cmp_time.exe
	./cmp_time.exe

app.exe: $(OUT)main.o $(OBJS)
	$(CC) -o $@ $^

unit_tests.exe: $(OUT)check_main.o $(OBJS) $(OBJS_UNIT)
	$(CC) -o $@ $^ -lcheck

cmp_time.exe: $(OUT)analysis.o $(OUT)mysort.o
	$(CC) -o $@ $^

$(OUT)analysis.o: $(CMP_TIME)analysis.c $(CMP_TIME)analysis.h
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)mysort.o: $(CMP_TIME)mysort.c $(CMP_TIME)mysort.h
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)main.o: $(SRC)main.c $(INC)main.h $(INC)filter_file.h $(INC)io_file.h $(INC)sort_file.h
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)filter_file.o: $(SRC)filter_file.c $(INC)filter_file.h
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)io_file.o: $(SRC)io_file.c $(INC)io_file.h
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)sort_file.o: $(SRC)sort_file.c $(INC)sort_file.h $(INC)main.h
	cd out && $(CC) $(CFLAGS) -c ../$<


$(OUT)check_main.o: $(UNIT_SRC)check_main.c $(UNIT_INC)check_main.h $(UNIT_INC)check_io_file.h \
$(UNIT_INC)check_filter_file.h $(UNIT_INC)check_sort_file.h
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)check_io_file.o: $(UNIT_SRC)check_io_file.c $(UNIT_INC)check_io_file.h
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)check_filter_file.o: $(UNIT_SRC)check_filter_file.c $(UNIT_INC)check_filter_file.h
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)check_sort_file.o: $(UNIT_SRC)check_sort_file.c $(UNIT_INC)check_sort_file.h
	cd out && $(CC) $(CFLAGS) -c ../$<