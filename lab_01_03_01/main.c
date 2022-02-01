#include <stdio.h>
#include <math.h>

double count_volume(double volume_1, double volume_2);

double count_temperature(double volume_1, double temp_1, double volume_2, double temp_2);

int main(void)
{
    setbuf(stdout, NULL);
	
    double v1, t1, v2, t2;
    printf("Enter V1, T1, V2, T2: ");
    scanf("%lf%lf%lf%lf", &v1, &t1, &v2, &t2);
	
    double v = count_volume(v1, v2);
    double t = count_temperature(v1, t1, v2, t2);
	
    printf("Volume & temperature of the resulting mixture: %lf %1f ", v, t);
	
    return 0;
}

double count_volume(double volume_1, double volume_2)
{
    return volume_1 + volume_2;
}

double count_temperature(double volume_1, double temp_1, double volume_2, double temp_2)
{
    double volume = count_volume(volume_1, volume_2);
    return (volume_1 * temp_1 + volume_2 * temp_2) / volume;
}
