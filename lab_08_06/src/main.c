#include "../inc/main.h"
#include "../inc/io.h"
#include "../inc/matrix_conversion.h"
#include "../inc/multiplication.h"

int main(void)
{
    setbuf(stdout, NULL);
    int rc = SUCCESSFUL;

    matrix_t matrix_1, matrix_2, result;
    matrix_1.data = NULL;
    matrix_2.data = NULL;
    result.data = NULL;

    rc = read_matrix(&matrix_1);
    if (rc == SUCCESSFUL)
    {
        rc = read_matrix(&matrix_2);
        if (rc == SUCCESSFUL)
        {
            rc = to_square(&matrix_1);
            if (rc == SUCCESSFUL)
            {
                rc = to_square(&matrix_2);
                if (rc == SUCCESSFUL)
                {
                    rc = to_one_size(&matrix_1, &matrix_2);
                    if (rc == SUCCESSFUL)
                    {
                        rc = multiplication(&matrix_1, &matrix_2, &result);
                        if (rc == SUCCESSFUL)
                        {
                            print_matrix(&result);
                            free_matrix_mem(&result);
                        }
                        free_matrix_mem(&matrix_1);
                        free_matrix_mem(&matrix_2);
                    }
                }
            }
        }
        else
            free_matrix_mem(&matrix_1);
    }

    return rc;
}