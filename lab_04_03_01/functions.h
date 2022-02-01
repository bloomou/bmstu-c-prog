#define NUM_WORDS 128
#define NUM_SIGNS 9
#define LEN_STR 256
#define LEN_WORD 16
#define ALPHABET 256

#define SEPARATORS ",;:-.!? "

#define SUCCESSFUL 0
#define TOO_LONG_STR -1
#define TOO_LONG_WORD -2
#define EMPTY_STRING -3

char new_string(char **words, int n, char *string);

char *my_strcat(char *str_1, char *str_2);

void delete_duplicates(char *word);

void transform(char *buf, char **matr, int n, int m);

int scan_string(char *str, int size);
