#include "main.h"
#include "sort_students.h"
#include "new_file_substring.h"
#include "delete_students.h"

int main(int argc, char **argv)
{
    int exit;
    if (argc == ARGS_AMOUNT_TASK_A_C || argc == ARGS_AMOUNT_TASK_B)
        exit = SUCCESSFUL;
    else
        exit = INVALID_ARGS;
    if (exit == SUCCESSFUL)
    {
        if (strcmp(argv[1], "sb") == 0 && argc == ARGS_AMOUNT_TASK_A_C)
        {
            exit = command_sort_students(argv[2]);
            if (exit == SUCCESSFUL)
                print_students(argv[2]);
        }
        else if (strcmp(argv[1], "fb") == 0 && argc == ARGS_AMOUNT_TASK_B)
            exit = command_students_with_substr(argv[2], argv[3], argv[4]);
        else if (strcmp(argv[1], "db") == 0 && argc == ARGS_AMOUNT_TASK_A_C)
            exit = command_delete_students(argv[2]);
        else
            exit = INVALID_ARGS;
    }
    return exit;
}
