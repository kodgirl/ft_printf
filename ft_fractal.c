/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:26:20 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/16 19:33:22 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*float_tostr(t_float *number, t_struct *flags)
{
	char	*str;
	t_str	ind;
	int		size_int;

	ind.i = 0;
	ind.j = 1;
	size_int = ft_sizeint(number->integer, flags->value_f);
	if (flags->p == 0 && !flags->dack_prec)
		flags->p = 6;
	str = ft_memalloc(size_int + flags->p + 2);
	while (ind.i < size_int)
	{
		str[ind.i] = number->integer[size_int - ind.i - 1] + '0';
		++ind.i;
	}
	if (!flags->p && flags->dack_prec &&\
			number->fract[MAX_FRACT_SIZE - 1] >= 5)
		str[ind.i - 1] += 1;
	else if (!flags->dack_prec || flags->sharp == 1)
	{
		str[ind.i++] = '.';
		ft_for_float(&ind, str, flags, number);
	}
	return (str);
}

void	ft_mass_multiply(char *buffer, int num)
{
	int i;

	i = 0;
	while (i < MAX_SIZE_BUF)
	{
		buffer[i] *= num;
		++i;
	}
}

void	ft_longnum_to_5power(char *buffer, int power)
{
	while (power)
	{
		ft_mass_multiply(buffer, 5);
		ft_beatuful_mass(buffer, MAX_SIZE_BUF);
		--power;
	}
}

void	ft_five_to_power(t_buf_power *buffer, int to_power)
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

void	ft_fract_sum(t_float *number, t_buf_power *buffer)
{
	int		i;
	int		power;
	char	*start;

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
