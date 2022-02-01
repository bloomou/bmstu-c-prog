#include <stdio.h>
#include <math.h>

#define PI acos(-1)

double count_area(double side_1, double side_2, double angle_1_2);

int main(void)
{
	setbuf(stdout, NULL);
	
	double a, b, angle;
	printf("Enter a, b & angle (in degrees): ");
	scanf("%lf%lf%lf", &a, &b, &angle);
	
	double s = count_area(a, b, angle);
	
	printf("Area: %lf", s);
	
	return 0;
}

double count_area(double side_1, double side_2, double angle_1_2)
{
	angle_1_2 = angle_1_2 * (PI / 180.0);
	double h = tan(angle_1_2) * (side_2 - side_1) / 2;
	double area = fabs((side_1 + side_2) * h / 2);
	return area;
}
