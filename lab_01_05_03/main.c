#include <stdio.h>

int greatest_common_divisor(int x, int y);

int main(void)
{
    setbuf(stdout, NULL);
	
    int a, b, rc, exit;
    printf("Input two numbers a & b: ");
    rc = scanf("%d%d", &a, &b);
	
    if (rc == 2)
    {
        if ((a > 0) && (b > 0))
        {
            int gcd = greatest_common_divisor(a, b);
            printf("Greatest common divisor of a & b: %d", gcd);
            exit = 0;
        }
        else
        {
            printf("Error: numbers should be positive");
            exit = -1;
        }
    }
    else
    {
        printf("Error: input error");
        exit = -2;
    }
    return exit;
}

int greatest_common_divisor(int x, int y)
{
    int result;
    while (x != y)
    {
        if (x > y)
            x = x - y;
        if (y > x)
            y = y - x;
    }
    result = x;
    return result;
}
