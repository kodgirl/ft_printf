/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:52:40 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/16 20:26:06 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	us_int_len(unsigned short int value, t_struct *inf)
{
	int i;

	i = 0;
	if (value == 0)
	{
		if (inf->plus && !inf->nv)
			i++;
		if (!inf->dack_prec)
			i++;
		return (i);
	}
	else
	{
		if (inf->space && !inf->plus)
			i++;
		if (inf->plus)
			i++;
	}
	while (value != 0)
	{
		value /= 10;
		i++;
	}
	return (i);
}

int	ul_int_len(unsigned long int value, t_struct *inf)
{
	int i;

	i = 0;
	if (value == 0)
	{
		if (inf->plus && !inf->nv)
			i++;
		if (!inf->dack_prec)
			i++;
		return (i);
	}
	else
	{
		if (inf->space && !inf->plus)
			i++;
		if (inf->plus || inf->sharp)
			i++;
	}
	while (value != 0)
	{
		value /= 10;
		i++;
	}
	return (i);
}

int	int_len(long int value, t_struct *inf)
{
	int i;

	i = 0;
	if (value == 0)
	{
		i += (inf->plus && !inf->nv) ? 1 : 0;
		i += (!inf->dack_prec || inf->sharp) ? 1 : 0;
		return (i);
	}
	else if (value < 0)
	{
		i++;
		inf->nv = 1;
	}
	else
	{
		i += ((inf->space && !inf->plus) || inf->sharp) ? 1 : 0;
		i += (inf->plus) ? 1 : 0;
	}
	while (value != 0)
	{
		value /= 10;
		i++;
	}
	return (i);
}

int	ft_value_u(t_struct *inf, va_list list, int i)
{
	int len;

	len = 0;
	if (i == 1 || i == 2)
	{
		inf->value_d = va_arg(list, unsigned long);
		len = ul_int_len(inf->value_d, inf);
	}
	else if (i == 3)
	{
		inf->value_d = va_arg(list, unsigned int);
		len = us_int_len((short)inf->value_d, inf);
	}
	else if (i == 4)
	{
		inf->value_d = va_arg(list, unsigned int);
		len = us_int_len((unsigned char)inf->value_d, inf);
	}
	if (i == 5)
	{
		inf->value_d = va_arg(list, unsigned int);
		len = int_len(inf->value_d, inf);
	}
	return (len);
}

int	ft_value_d(t_struct *inf, va_list list, int i)
{
	if (i == 1)
	{
		inf->value_d = va_arg(list, long int);
		return ((int)int_len((long)inf->value_d, inf));
	}
	else if (i == 2)
	{
		inf->value_d = va_arg(list, long long);
		return ((int)int_len(inf->value_d, inf));
	}
	else if (i == 3)
	{
		inf->value_d = va_arg(list, int);
		return ((int)int_len((short)inf->value_d, inf));
	}
	else if (i == 4)
	{
		inf->value_d = va_arg(list, int);
		return ((int)int_len((char)inf->value_d, inf));
	}
	inf->value_d = va_arg(list, int);
	return ((int)int_len(inf->value_d, inf));
}
