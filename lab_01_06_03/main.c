#include <stdio.h>
#include <math.h>

#define EPS 1e-8

double vector_coordinates(double start, double end);

double skew_product(double x1, double y1, double x2, double y2);

int line_and_dot(double p);

int main(void)
{
    setbuf(stdout, NULL);
    int exit;
	
    double xq, yq, xr, yr, xp, yp;
    printf("Arbitrary point is point P, straight line is QR. \n");
    printf("Input coordinates of the three points Q, R & P: ");
    int rc = scanf("%lf%lf%lf%lf%lf%lf", &xq, &yq, &xr, &yr, &xp, &yp);

    if (rc == 6)
    {
        double x_qr = vector_coordinates(xq, xr);
        double y_qr = vector_coordinates(yq, yr);
        double x_qp = vector_coordinates(xq, xp);
        double y_qp = vector_coordinates(yq, yp);
		
        if ((fabs(x_qr) <= EPS) && (fabs(y_qr) <= EPS))
        {
            printf("Error: degenerate straight line");
            exit = -1;
        }
        else
        {
            double product_qr_qp = skew_product(x_qr, y_qr, x_qp, y_qp);
            int result = line_and_dot(product_qr_qp);
            printf("Result: %d ", result);
            exit = 0;
        }
    }
    else
    {
        printf("Error: input error");
        exit = -2;
    }
    return exit;
}

double vector_coordinates(double start, double end)
{
    return end - start;
}

double skew_product(double x1, double y1, double x2, double y2)
{
    double x = x1 * y2 - x2 * y1;
    return x;
}

int line_and_dot(double product)
{
    int result;
    if (product > 0)
        result = 0;
    else if (fabs(product) <= EPS)
        result = 1;
    else
        result = 2;
    return result;
}
