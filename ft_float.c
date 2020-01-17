/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:00:25 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/16 19:36:57 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

char	*nan_or_inf(t_print divis, t_struct *flags)
{
	flags->nan_or_inf = 1;
	if (divis.t_byte.mant << 1)
	{
		flags->plus = 0;
		flags->zero = 0;
		flags->p = 0;
		flags->space = 0;
		return ("nan");
	}
	flags->zero = 0;
	flags->p = 0;
	return ("inf");
}

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
	t_power_of_2		powers;
	t_float				number;

	divis.number = a;
	divis.t_byte.exp -= 16383;
	if (divis.t_byte.exp == -16384)
		return (nan_or_inf(divis, flags));
	if (divis.t_byte.sign == 1 && !flags->nan_or_inf)
	{
		flags->nv = 1;
		flags->plus = 0;
	}
	flags->i = 0;
	flags->mask = 1L << 63;
	ft_bzero(&powers, sizeof(t_power_of_2));
	while (flags->mask != 0)
	{
		if ((divis.t_byte.mant & flags->mask) != 0)
			ft_power_to_massive(&powers, divis.t_byte.exp - flags->i);
		flags->i++;
		flags->mask >>= 1;
	}
	number = ft_long_ariphm(powers);
	return (float_tostr(&number, flags));
}
