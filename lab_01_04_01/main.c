#include <stdio.h>

#define APARTMENTS_ON_ONE_FLOOR 4
#define NUM_OF_FLOORS 9

int count_entrance(int number_of_apartment, int num_of_apartments_in_entrance);

int count_floor(int number_of_apartment, int num_of_apartments_in_entrance);

int main(void)
{
    setbuf(stdout, NULL);
    const int in_one_entrance = APARTMENTS_ON_ONE_FLOOR * NUM_OF_FLOORS;
	
    int n;
    printf("Enter apartment number: ");
    scanf("%d", &n);
	
    int entrance = count_entrance(n, in_one_entrance);
    int floor = count_floor(n, in_one_entrance);
	
    printf("Entrance number & floor number: %d %d ", entrance, floor);
	
    return 0;
}

int count_entrance(int number_of_apartment, int num_of_apartments_in_entrance)
{
    return (number_of_apartment - 1) / num_of_apartments_in_entrance + 1;
}

int count_floor(int number_of_apartment, int num_of_apartments_in_entrance)
{
    return ((number_of_apartment - 1) % num_of_apartments_in_entrance) / APARTMENTS_ON_ONE_FLOOR + 1;
}
