#include "printf.h"

void    ft_mass_multiply(char *buffer, int num)
{
    int i;
    
    i = 0;
    while (i < MAX_SIZE_BUF)
    {
        buffer[i] *= num;
        ++i;
    } 
}

void    ft_longnum_to_5power(char *buffer, int power)
{
    while (power)
    {
        ft_mass_multiply(buffer, 5);
        ft_beatuful_mass(buffer, MAX_SIZE_BUF);
        --power;
    }
}

void    ft_five_to_power(t_buf_power *buffer, int to_power)
{
    int diff;

    if (!buffer->init)
    {
        buffer->buf[0] = 5;
        buffer->power = 1;
        buffer->init = True;
    }
    diff = to_power - buffer->power;
    ft_longnum_to_5power(buffer->buf, diff);
    buffer->power = to_power;
    // print_buffer(buffer, 50);        
}

void    ft_fract_sum(t_float *number, t_buf_power *buffer)
{
	int i;
	int power;
	char *start;

	i = 0;
	power = buffer->power;
	start = number->fract + MAX_FRACT_SIZE - power;
	while (power && i < MAX_SIZE_BUF)
	{
		start[i] += buffer->buf[i];
		++i;
		--power;
	}
}
