#include "new_file_substring.h"

int command_students_with_substr(char *str_1, char *str_2, char *str_3)
{
    int rc = SUCCESSFUL;
    FILE *f;
    f = fopen(str_1, "rb");
    if (f != NULL)
    {
        int size;
        if (check_struct_file(f, &size) == SUCCESSFUL)
            rc = new_file(f, size, str_2, str_3);
        else
            rc = WRONG_SIZE_FILE;
        fclose(f);
    }
    else
        rc = NO_FILE;
    return rc;
}

int new_file(FILE *f, int size, char *new_file, char *string)
{
    int rc = SUCCESSFUL;
    FILE *g = fopen(new_file, "wb");
    if (g != NULL)
    {
        rc = NO_STUDENTS;
        for (int i = 0; i < size; i++)
        {
            student current_student = get_student(f, i);
            if (strstr(current_student.surname, string) == current_student.surname)
            {
                fwrite(&current_student, sizeof(student), 1, g);
                rc = SUCCESSFUL;
            }
        }
        fclose(g);
    }
    else
        rc = NO_FILE;
    return rc;
}
