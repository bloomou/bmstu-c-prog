#include <stdio.h>
#include <math.h>

double calc_s(double t, double e);

double calc_f(double t);

double absolute_error(double f, double s);

double relative_error(double f, double s);

int main(void)
{
    setbuf(stdout, NULL);
    int exit;
	
    double x, eps;
    printf("Input x & eps: ");
    int rc = scanf("%lf%lf", &x, &eps);
	
    if (rc == 2)
    {
        if ((fabsl(x) <= 1) & (eps > 0) & (eps <= 1))
        {
            double s_x = calc_s(x, eps);
            double f_x = calc_f(x);
            double abs_error = absolute_error(f_x, s_x);
            double rel_error = relative_error(f_x, s_x);
            printf("Result (f(x), s(x), absolute & relative errors): %lf %lf %lf %lf ", f_x, s_x, abs_error, rel_error);
            exit = 0;
        }
        else
        {
            printf("Error: limited range of acceptable values");
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

double calc_s(double t, double e)
{
    double summ = 0;
    double prev;
    int n = 1;
    int k = 1;
    while (fabs(t) > e)
    {
        summ += t;
        prev = t;
        t = pow(-1, k) * prev * t * t * n / (n + 2);
        n += 2;
        k += 1;
    }
    return summ;
}

double calc_f(double t)
{
    double func = atan(t);
    return func;
}

double absolute_error(double f, double s)
{
    double error = fabs(f - s);
    return error;
}

double relative_error(double f, double s)
{
    double error;
    error = absolute_error(f, s) / fabs(f);
    return error;
}
