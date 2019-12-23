/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:02:44 by bjasper           #+#    #+#             */
/*   Updated: 2019/12/23 16:08:57 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <inttypes.h>
# include <limits.h>

# define MAX_SIZE_BUF       10 //5000

typedef struct              s_float
{
    char                   integer[4932];
    char                    fract[16383];
    int                    size_int;
    int                    size_fract;
    int                    fract_length;
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

typedef struct  s_struct
{
    int plus; //f
    int minus; //f
    int space; //f
    int sharp; //f
    int zero; //f
    int width; // ширина
    int widthisneg; // ширина отрицательная
    int precision; // точность
    int h;
    int hh;
    int l;
    int ll;
    int value_is_neg;
    int dack_prec; //если стоит точка без числа т.е. если не указана точность
}   t_struct;

void    ft_beatuful_mass(char *long_num);
void    ft_mass_sum(char *long_num1, char *long_num2);
void    ft_longnum_to_2power(char *long_num, int power);
void    ft_buf_riseto_power(t_buf_power *buffer, int to_power);
void    ft_long_ariphm(t_power_of_2 powers);
void	ft_bzero(void *s, size_t n);
void    ft_power_to_massive(t_power_of_2 *powers, int power);
char    *ft_float(long double a);
void    ft_mass_multiply(char *buffer, int num);
void    print_float_number(t_float *number, int len_int, int len_fract);
void    print_struct_powers(t_power_of_2 *powers);
void    ft_five_to_power(t_buf_power *buffer, int to_power);
void    ft_fract_sum(t_float *number, t_buf_power *buffer);
void    ft_longnum_to_5power(char *buffer, int power);
void    ft_mass_multiply(char *buffer, int num);



void    print_buffer(t_buf_power *buf, int print_len);                          //delete after
void    print_float_number(t_float *number, int len_int, int len_fract);
void    print_struct_powers(t_power_of_2 *powers);


#endif
