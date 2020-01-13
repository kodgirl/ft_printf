#include "printf.h"

int		ft_sizeint(char *integer, long double value)
{
	int i;
	
	i = MAX_INTEGER_SIZE;
	while (i > 0 && integer[i - 1] == 0)
		--i;
	i += ((value > -1 && value <= 0) || (value < 1 && value >= 0)) ? 1 : 0;
	return (i);
}

char *float_tostr(t_float *number, t_struct *flags)
{
	char *str;
	int i;
	int j;
	int size_int;
	
	i = 0;
	j = 1;
	size_int = ft_sizeint(number->integer, flags->value_f);
	if (flags->precision == 0 && !flags->dack_prec)
		flags->precision = 6;
	str = ft_memalloc(size_int + flags->precision + 2);
	while (i < size_int)
	{
		str[i] = number->integer[size_int - i - 1] + '0';
		++i;
	}
	// if (size_int == 1 && str[i])
	// {
		
	// }
	if (flags->precision == 0 && flags->dack_prec && number->fract[MAX_FRACT_SIZE - 1] >= 53 && MAX_FRACT_SIZE >= 1)
		str[i - 1] += 1;
	else if (!flags->dack_prec || flags->sharp == 1) // tut sharp
	{
		str[i++] = '.';
		while (j <= flags->precision && MAX_FRACT_SIZE - j >= 0) // eto
		{
			str[i] = number->fract[MAX_FRACT_SIZE - j] + '0';
			++j;
			++i;
		}
		--i;
		if (MAX_FRACT_SIZE - j - 2 >= 0 && number->fract[MAX_FRACT_SIZE - j - 2] + 48 >= '5')
		{
			if (str[i] < '9' && str[i] != '.')
				str[i] += 1;
			else
			{
				while (str[i] == '9' && str[i] != '.')
				{
					if (str[i - 1] == '.') // eto
						str[i - 2] += 1; // eto
					str[i] = '0';
					if (str[i - 1] != '9' && str[i - 1] != '.') // eto
					{
						str[i - 1] += 1;
						break;
					}
					--i;
				}
			}
		}
	}
	return(str);
}

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
