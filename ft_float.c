/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:00:25 by bjasper           #+#    #+#             */
/*   Updated: 2019/12/19 21:12:51 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <stdlib.h>

# define MAX_SIZE_BUF       5000
typedef struct              s_float
{
    char                   integer[4932];
    int                    fract[16383];
    int                    size_int;
    int                    size_fract;
}                           t_float;


typedef union               s_print		    
{
    long double             number;
    struct                 
    {
        unsigned long long  mant:64;
	    short int           exp:15;
	    unsigned int        sign:1;
    }                       t_byte;
}						    t_print;

typedef enum                e_boolen
{
    True = 1,
    False = !True
}                           t_boolen;

typedef struct              s_buf_power
{
    char buf[MAX_SIZE_BUF];
    int power;
    t_boolen init;
}                           t_buf_power;

typedef struct              s_power_of_2
{
    int integer[64];
    int fract[64];
    int size_int;
    int size_fract;
}                           t_power_of_2;



void	ft_bzero(void *s, size_t n)
{
	unsigned char *str;

	str = (unsigned char *)s;
	while (n)
	{
		*str = '\0';
		str++;
		n--;
	}
}

/*
** функция возведения числа в положительную степень
**
*/

long int    ft_power(int a, int b)
{
    while (--b)
    {
        a *= a;
    }
    return ((long int)a);
}
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

/*
**  если экспонента - сдвиг положительна, то возводит 2 в степень полученного числа. и идет в нам_ту_массив
**  если экспонента - сдвиг отрицательна, то возводит 5 в степень модуля полученного числа. и идет в нам_ту_массив
*/

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
    printf("\n");
    f = 0;
    while (f < len_fract)
    {
        printf("%d ", number->fract[i]);
        ++i;
    }
    printf("\n");
    printf("Size_int: %d\n ", number->size_int);  
    printf("Size_fract: %d\n ", number->size_fract); 
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
    print_float_number(&number, 49, 0);                              
    fract_index = powers.size_fract - 1;
    // while (fract_index >= 0)
    // {
        
    // } 
}

/*
** проверяет маской мантиссу
** если встречает включенный бит, идет в длинную арифметику
*/

void    ft_power_to_massive(t_power_of_2 *powers, int power)
{
    if (power >= 0)
    {
        powers->integer[powers->size_int] = power;
        powers->size_int++;
    }
    else
    {
        powers->fract[powers->size_fract] = power;
        powers->size_fract++;
    }
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

char    *ft_float(long double a)
{
    t_print             divis;                               //деление числа на знак, мантиссу и экспоненту
    unsigned long long  mask;
    t_float             num; 
    int                 i;                                //деление числа на целую и дробную части
    t_power_of_2        powers;
    unsigned long long  mant;
    
    divis.number = a;
    divis.t_byte.exp -= 16383;
    i = 0;
    mask = 1; 
    mask = mask << 63;
    mant = divis.t_byte.mant;                                          //маска для мантиссы
    ft_bzero(&powers, sizeof(t_power_of_2));
    while (mant != 0)                                    //пока мантисса есть, число будет считаться
    {
        if ((mant & mask) != 0)                   //проверяется наличие бита мантиссы
            ft_power_to_massive(&powers, divis.t_byte.exp - i);                    
        ++i;
        mant = mant << 1;
    }
    print_struct_powers(&powers);
    ft_long_ariphm(powers);
    return (NULL);
}

int main()
{
   long double a;
   
   a = 23455343387634786780279748243.0L;
   printf("result %s", ft_float(a)); 
   return (0);
}





// for (int i = 15; i >= 0 ; --i)
    // {
    //     printf("%d", (divis.t_byte.exp >> i) & 1 ? 1 : 0); 
    // }
    // printf("\n");
    // for (int i = 63; i >= 0 ; --i)
    // {
    //     printf("%d", (divis.t_byte.mant >> i) & 1 ? 1 : 0); 
    // }