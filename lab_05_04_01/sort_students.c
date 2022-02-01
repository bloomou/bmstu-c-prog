#include "sort_students.h"

int command_sort_students(char *string)
{
    int rc = SUCCESSFUL;
    FILE *f;
    f = fopen(string, "r+b");
    if (f != NULL)
    {
        int size;
        if (check_struct_file(f, &size) == SUCCESSFUL)
            sort_students(f, size);
        fclose(f);
    }
    else
        rc = NO_FILE;
    return rc;
}

void sort_students(FILE *f, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - i - 1; j++)
        {
            char *surname_1 = get_student(f, j).surname;
            char *surname_2 = get_student(f, j + 1).surname;
            if (strcmp(surname_1, surname_2) > 0)
                swap(f, j, j + 1);
            else if (strcmp(surname_1, surname_2) == 0)
            {
                char *name_1 = get_student(f, j).name;
                char *name_2 = get_student(f, j + 1).name;
                if (strcmp(name_1, name_2) > 0)
                    swap(f, j, j + 1);
            }
        }
}

void swap(FILE *f, int pos_1, int pos_2)
{
    student std_1 = get_student(f, pos_1);
    student std_2 = get_student(f, pos_2);

    put_student_by_pos(f, &std_1, pos_2);
    put_student_by_pos(f, &std_2, pos_1);
}

void put_student_by_pos(FILE *f, student *stud, int pos)
{
    fseek(f, pos * sizeof(student), SEEK_SET);
    fwrite(stud, sizeof(student), 1, f);
}

int check_size_of_file(FILE *f)
{
    fseek(f, 0, SEEK_END);
    int size = WRONG_SIZE_FILE;
    if (ftell(f) % sizeof(student) == 0)
        size = ftell(f) / sizeof(student);
    return size;
}

int check_struct_file(FILE *f, int *size)
{
    int rc = SUCCESSFUL;
    *size = check_size_of_file(f);
    if (*size > 0)
    {
        for (int i = 0; i < *size; i++)
        {
            student current_student = get_student(f, i);
            for (int j = 0; j <= LEN_SURNAME; j++)
                if (current_student.surname[j] == '\0' && j > 0)
                {
                    rc = SUCCESSFUL;
                    break;
                }
            if (rc == SUCCESSFUL)
            {
                rc = WRONG_LEN_NAME;
                for (int j = 0; j <= LEN_NAME; j++)
                    if (current_student.name[j] == '\0' && j > 0)
                    {
                        rc = SUCCESSFUL;
                        break;
                    }
            }
        }
    }
    else
        rc = WRONG_SIZE_FILE;
    return rc;
}

student get_student(FILE *f, int index)
{
    student current;
    fseek(f, index * sizeof(student), SEEK_SET);
    fread(&current, sizeof(student), 1, f);
    return current;
}

void print_students(char *string)
{
    FILE *f = fopen(string, "rb");
    if (f != NULL)
    {
        int size = check_size_of_file(f);
        if (size > 0)
        {
            fseek(f, 0, SEEK_SET);
            for (int i = 0; i < size; i++)
            {
                student stud;
                fread(&stud, sizeof(student), 1, f);
                printf("%s\n%s\n%u %u %u %u\n", stud.surname, stud.name, \
                stud.marks[0], stud.marks[1], stud.marks[2], stud.marks[3]);
            }
        }
        fclose(f);
    }
}