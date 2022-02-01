/* Bubble sorting in ascending order */

#include "main.h"
#include "new_file.h"
#include "sort_file.h"
#include "print_file.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int exit = SUCCESSFUL;
    FILE *f;

    if (argc != ARGS_AMOUNT)
        exit = NO_ARGS;
    if (exit == SUCCESSFUL)
    {
        if (strchr(INTEGER, argv[1][0]) != NULL)
        {
            f = fopen(argv[2], "wb");
            int number = atoi(argv[1]);
            command_create_file(f, &exit, number);
            fclose(f);
        }
        else if (strcmp(argv[1], "p") == 0)
        {
            f = fopen(argv[2], "rb");
            command_print_file(f, &exit);
            fclose(f);
        }
        else if (strcmp(argv[1], "s") == 0)
        {
            f = fopen(argv[2], "rb+");
            command_sort_file(f, &exit);
            fclose(f);
        }
        else
            exit = INVALID_ARGS;
    }
    return exit;
}
