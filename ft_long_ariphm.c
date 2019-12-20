#include "printf.h"

void    ft_beatuful_mass(char *long_num)
{
    int next;
    int current;
    
    current = 0;
    next = current + 1;
    while (next < MAX_SIZE_BUF)
    {
        if (long_num[current] > 9)
        {
            long_num[next] = long_num[next] + long_num[current] / 10;
            long_num[current] = long_num[current] % 10;
        }
        ++current;
        ++next;
    }
    
}

void    ft_mass_sum(char *long_num1, char *long_num2)
{
    int i;
    
    i = 0;
    while (i < MAX_SIZE_BUF)
    {
        long_num1[i] += long_num2[i];
        ++i;
    } 
}

void ft_longnum_to_2power(char *long_num, int power)
{
    while (power)
    {
        ft_mass_sum(long_num, long_num);
        ft_beatuful_mass(long_num);
        --power;
    }
}

void    ft_buf_riseto_power(t_buf_power *buffer, int to_power)
{
    int diff;

    if (!buffer->init)
    {
        if (to_power == 0)
        {
            buffer->buf[0] = 1;
            buffer->power = 0;
        }
        else
        {
            buffer->buf[0] = 2;
            buffer->power = 1;
        } 
        buffer->init = True;
    }
    diff = to_power - buffer->power;
    ft_longnum_to_2power(buffer->buf, diff);
    buffer->power = to_power;
    print_buffer(buffer, 50);        
}


void    ft_long_ariphm(t_power_of_2 powers)
{
    t_buf_power buffer;
    int int_index;
    int fract_index;
    t_float number;   

    ft_bzero(&number, sizeof(t_float));
    ft_bzero(&buffer, sizeof(t_buf_power));
    buffer.init = False;
    int_index = powers.size_int - 1;
    while (int_index >= 0)
    {
        ft_buf_riseto_power(&buffer, powers.integer[int_index]);
        ft_mass_sum(number.integer, buffer.buf);
        ft_beatuful_mass(number.integer);
        --int_index;
    }   
    ft_bzero(&buffer, sizeof(t_buf_power));
    buffer.init = False;                           
    fract_index = 0;
    number.fract_length = 0;
    printf("\n\n\n\n");
    while (fract_index < powers.size_fract)
    {
        ft_five_to_power(&buffer, -powers.fract[fract_index]);
        ft_fract_sum(&number, &buffer);
        ft_beatuful_mass(number.fract);
        ++fract_index;
    } 
    print_float_number(&number, 49, 0);
}
