#define LEN_STR 256

#define SUCCESSFUL 0
#define NO_END -1
#define EMPTY_STRING -2
#define NUMBERS "0123456789"
#define EXPS "eE"
#define SIGNS "+-"

#define TRUE 1
#define FALSE 0

int skip_spaces_at_beginning(char *string, int n);

int skip_spaces_at_end(char *string, int n);

int is_end(int n, int index);

int nums_check(char *string, int n, int index);

int processing(char *string, int n);

int exp_part_check(char *string, int n, int index);

int end_of_number(char *string, int n, int index);

void print_result(int res);
