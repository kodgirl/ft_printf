/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:00:25 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/13 16:32:41 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <float.h>

void	ft_power_to_massive(t_power_of_2 *powers, int power)
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

char	*ft_float(long double a, t_struct *flags)
{
	t_print				divis;
	unsigned long long	mask;
	int					i;
	t_power_of_2		powers;
	t_float				number;

	divis.number = a;
	divis.t_byte.exp -= 16383;
	if (divis.t_byte.exp == -16384)
	{
		flags->nan_or_inf = 1;
		if (divis.t_byte.mant << 1)
		{
			flags->plus = 0;
			flags->zero = 0;
			flags->precision = 0;
			flags->space = 0;
			return ("nan");
		}
		else
		{
			//flags->space = 0;
			flags->zero = 0;
			flags->precision = 0;
			return ("inf");
		}
	}
	if (divis.t_byte.sign == 1 && !flags->nan_or_inf)
	{
			flags->value_is_neg = 1;
			flags->plus = 0;
	}
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
	number = ft_long_ariphm(powers);
	return (float_tostr(&number, flags));
}
