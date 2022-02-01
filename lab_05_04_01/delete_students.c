#include "delete_students.h"

int command_delete_students(char *string)
{
    int rc = SUCCESSFUL;
    FILE *f;
    f = fopen(string, "rb");
    if (f != NULL)
    {
        int size;
        if (check_struct_file(f, &size) == SUCCESSFUL)
        {
            fseek(f, 0, SEEK_SET);
            FILE *tmp;
            tmp = fopen("tmp_file.bin", "w+b");
            rc = check_students(f, size, tmp);
            fclose(f);
            if (rc == SUCCESSFUL)
            {
                int new_size = check_size_of_file(tmp);
                if (new_size > 0)
                {
                    f = fopen(string, "wb");
                    fseek(tmp, 0, SEEK_SET);
                    delete_students(f, new_size, tmp);
                    fclose(f);
                }
                else
                    rc = WRONG_SIZE_FILE;
            }
            fclose(tmp);
        }
        else
            rc = WRONG_SIZE_FILE;
    }
    else
        rc = NO_FILE;
    return rc;
}

int check_students(FILE *f, int size, FILE *t)
{
    int rc = NO_STUDENTS;
    double overall_avg = overall_avg_mark(f, size);
    for (int i = 0; i < size; i++)
    {
        student current_student = get_student(f, i);
        double student_avg = avg_mark_of_student(&current_student);
        if (student_avg >= overall_avg)
        {
            fwrite(&current_student, sizeof(student), 1, t);
            rc = SUCCESSFUL;
        }
    }
    return rc;
}

void delete_students(FILE *f, int size, FILE *t)
{
    for (int i = 0; i < size; i++)
    {
        student tmp_student = get_student(t, i);
        fwrite(&tmp_student, sizeof(student), 1, f);
    }
}

double avg_mark_of_student(student *stud)
{
    double sum = 0;
    for (int i = 0; i < COUNT_MARKS; i++)
        sum += stud->marks[i];
    return sum / COUNT_MARKS;
}

double overall_avg_mark(FILE *f, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        student current_student = get_student(f, i);
        sum += avg_mark_of_student(&current_student);
    }
    return sum / size;
}
