/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:00:25 by bjasper           #+#    #+#             */
/*   Updated: 2019/12/23 15:42:43 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

char    *ft_float(long double a)
{
    t_print             divis;
    unsigned long long  mask; 
    int                 i;
    t_power_of_2        powers;
    
    divis.number = a;
    divis.t_byte.exp -= 16383;
    i = 0;
    mask = 1L << 63;                           
    ft_bzero(&powers, sizeof(t_power_of_2));
    while (mask != 0)                                   
    {
        if ((divis.t_byte.mant & mask) != 0)         
            ft_power_to_massive(&powers, divis.t_byte.exp - i);                    
        ++i;
        mask >>= 1;
    }
    // print_struct_powers(&powers);
    ft_long_ariphm(powers);
    return (NULL);
}

int main()
{
   long double a;
   
   a = 2.6L;
   printf("result %s\n", ft_float(a)); 
   printf("result2 %Lf", a); 
   return (0);
}
