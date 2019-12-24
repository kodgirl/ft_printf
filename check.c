#include "printf.h"

void    print_buffer(t_buf_power *buf, int print_len)
{
    int i;
    i = 0;
    printf("Buffer = ");
    while (i < print_len)
    {
        printf("%d ", buf->buf[i]);
        ++i;
    }
    printf("\n");
    printf("Initialisation: %s\n", buf->init ? "True" : "False");
    printf("Power: %d\n ", buf->power);   
}

void    print_float_number(t_float *number, int len_int, int len_fract)
{
    int i;
    int f;

    i = 0;
    printf("Integer = ");
    while (i < len_int)
    {
        printf("%d ", number->integer[i]);
        ++i;
    }
    printf("\nFractal = ");
    f = 0;
    while (f < len_fract)
    {
        printf("%d", number->fract[f]);
        ++f;
    }
    printf("\n");
    printf("Size_int: %d\n ", number->size_int);  
    printf("Size_fract: %d\n ", number->size_fract); 
}

void print_struct_powers(t_power_of_2 *powers)
{
    int i;
    i = 0;
    while (i < 64)
    {
        printf("%d ", powers->integer[i]);
        ++i;
    }
    printf("\n");
    i = 0;
     while (i < 64)
    {
        printf("%d ", powers->fract[i]);
        ++i;
    }
    printf("\n");
    printf("%d\n ", powers->size_int);
    printf("%d\n", powers->size_fract);   
}
