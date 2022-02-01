#include <stdio.h>
#include <math.h>

#define NUM_OF_BYTES 4
#define BYTE 8

unsigned long int packaging(unsigned long int byte_a, unsigned long int byte_b, unsigned long int byte_c, unsigned long int byte_d);

void print_unpack(unsigned long int num);

void print_pack(unsigned long int num);

void print_of_result(unsigned long int res_of_packaging);

int main(void)
{
    setbuf(stdout, NULL);
    int exit;
	
    unsigned long int byte_1, byte_2, byte_3, byte_4;
    printf("Input values of four bytes: ");
    unsigned long int rc = scanf("%lu%lu%lu%lu", &byte_1, &byte_2, &byte_3, &byte_4);
    
    if (rc == NUM_OF_BYTES)
    {
        if (byte_1 > 255 || byte_2 > 255 || byte_3 > 255 || byte_4 > 255)
        {
            printf("Error: byte is more than 255 or less than 0");
            exit = -2;
        }
        else
        {
            unsigned long int byte_1_new = byte_1 << BYTE * (NUM_OF_BYTES - 1);
            unsigned long int byte_2_new = byte_2 << BYTE * (NUM_OF_BYTES - 2);
            unsigned long int byte_3_new = byte_3 << BYTE * (NUM_OF_BYTES - 3);
            unsigned long int byte_4_new = byte_4 << BYTE * (NUM_OF_BYTES - 4);
			
            unsigned long int packed = packaging(byte_1_new, byte_2_new, byte_3_new, byte_4_new);
            print_of_result(packed);
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

unsigned long int packaging(unsigned long int byte_a, unsigned long int byte_b, unsigned long int byte_c, unsigned long int byte_d)
{
    unsigned long int result = byte_a | byte_b | byte_c | byte_d;
    return result;
}

void print_pack(unsigned long int num)
{
    for (int i = BYTE * 4 - 1; i >= 0; i--)
        printf("%lu", (num >> i) % 2);
}

void print_unpack(unsigned long int num)
{
    for (int i = NUM_OF_BYTES - 1; i >= 0; i--)
        printf("%lu ", (num >> (i * BYTE)) % 256);
}

void print_of_result(unsigned long int res_of_packaging)
{
    printf("Result: ");
    printf("\n");
    print_pack(res_of_packaging);
    printf(" ");
    print_unpack(res_of_packaging);
}
