#define NUM_WORDS 128
#define NUM_SIGNS 9
#define LEN_STR 256
#define LEN_WORD 16

#define SEPARATORS ",;:-.!? "

#define SUCCESSFUL 0
#define TOO_LONG_WORD -1
#define NO_END -2
#define EMPTY_STRING -3
#define NO_WORDS -4

int check_word_len(char **words, int n);

int check_if_unique(char **words, int index);

void sort_words(char **matr, int n);

void swap(char **str_1, char **str_2);

void print_words(char **matr, int n);

void transform(char *buf, char **matr, int n, int m);

int split_into_words(char *string, char **words, int *flag);
