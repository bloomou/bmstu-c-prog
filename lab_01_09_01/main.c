#include <stdio.h>
#include <math.h>

int counting(void);

int main(void)
{
    setbuf(stdout, NULL);
	
    int result = counting();
    return result;
}

int counting(void)
{
    int exit;  
    double summ = 0;
    double g, x;
	
    printf("Input x: ");
    int rc = scanf("%lf", &x);
	
    if (rc == 1)
    {
        int n = 1;
        int flag = 1;
        while (x >= 0)
        {
            summ += sqrtl(x / n);
            n += 1;
            printf("Input x: ");
            rc = scanf("%lf", &x);
            if (rc != 1)
            {
                printf("Error: input error");
                exit = -1;
                flag = 0;
            }
        }
        if ((rc == 1) && (flag == 1))
        {
            g = sin(summ);
            printf("Result: %lf ", g);
            exit = 0;
        }
    }
    else
    {
        printf("Error: input error");
        exit = -1;
    }
    return exit;
}
