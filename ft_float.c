/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:00:25 by bjasper           #+#    #+#             */
/*   Updated: 2019/12/08 16:00:05 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "/Users/bjasper/bjasper/libft/libft.h"

typedef struct              s_float
{
    int                    prt1[4932];
    int                    prt2[16383];
}                           t_float;


typedef union               s_print		    
{
    long double             number;
    struct                  byte
    {
        unsigned long       mant: 64;
	    short int           exp: 15;
	    unsigned int        sign: 1;
    }                       t_byte;
}						    t_print;

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

void    ft_massive_summ(t_float *num, int temp_prt1, int temp_prt2)
{

}

/*
** число представляет как массив цифр (интов)
**
*/

void    ft_num_to_massive(t_float *num, long int temp, int power)
{
    
    int             i;
    int             temp_prt1[4932];                    //текущий массив целой части, который прибавляется к общему массиву
    int             temp_prt2[16383];                   //текущий массив дробной части, который прибавляется к общему массиву

    ft_bzero(&temp_prt1, 4932);                         //обнуление текущих массивов
    ft_bzero(&temp_prt2, 16383);
    i = 0;
    if (power >= 0)                                     //запись в массив целой части
    {
        while (temp >= 1)
        {
            temp_prt1[i] = temp % 10;
            temp /= 10;
            ++i;
        }        
    }
    else                                                //запись в массив дробной части в обратном порядке
    {
        power = -power;
        while (power >= 1)
        {
            temp_prt2[power - 1] = temp % 10;
            temp /= 10;
            --power;
        }
    }
    ft_massive_summ(num, temp_prt1, temp_prt2);
}

/*
**  если экспонента - сдвиг положительна, то возводит 2 в степень полученного числа. и идет в нам_ту_массив
**  если экспонента - сдвиг отрицательна, то возводит 5 в степень модуля полученного числа. и идет в нам_ту_массив
*/

void    ft_long_ariphm(short int exp, t_float num)
{
    long int temp;                                       //2 в степени экспоненты. временное число, которое надо записать в массив
    
    
    if((exp - 16383) >= 0)                               //положительная часть числа
    {
        temp = ft_power(2, exp - 16383);                 //возведение двойки в степень экспоненты
        ft_num_to_massive(&num, temp, exp - 16383);      //запись числа в массив интов
    }
    else                                                 //отрицательная часть числа
    {
        temp = ft_power(5, 16383 - exp);                 //5 в степени - экспаненты = 2 в степени экспоненты
        ft_num_to_massive(&num, temp, exp - 16383);      //запись числа в массив интов
    }
    
}

/*
** проверяет маской мантиссу
** если встречает включенный бит, идет в длинную арифметику
*/

void    ft_float(long double a)
{
    t_print         divis;                               //деление числа на знак, мантиссу и экспоненту
    short int       exp;                                 //перезапись частей числа
    unsigned long   mant;
    long long int   mask;
    t_float         num;                                 //деление числа на целую и дробную части

    divis.number = a;
    mask = 9223372036854775808;                          //маска для мантиссы. не изменяется
    exp = divis.t_byte.exp;                              //переписываются мантисса и экспонента, тк они не могут изменяться в юнион
    mant = divis.t_byte.mant;
    ft_bzero(&num.prt1, 4932);                           //обнуляются целая и дробная части числа
    ft_bzero(&num.prt2, 16383);    
    while (mant != 0)                                    //пока мантисса есть, число будет считаться
    {
        if ((mant & mask) != 0)                          //проверяется наличие бита мантиссы
        {
            ft_long_ariphm(exp, num);                    //функция рассчета числа
        }
        --exp;
        mant <<= 1;                                      //сдвигается бит мантиссы
    }
}

int main()
{
   long double a;
   
   a = 5;
   ft_float(a);
    
   return (0);
}