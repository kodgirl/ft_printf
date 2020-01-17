/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:36:50 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/16 19:36:57 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*hex_rev(t_struct *inf)
{
	int		i;
	int		g;
	char	*str;

	i = 0;
	g = 0;
	while (inf->value_hex[g + 1] != '\0')
		g++;
	str = ft_memalloc(g + 2);
	while (g >= 0)
	{
		if (inf->value_hex[g] >= 65 && inf->value_hex[g] <= 90 &&\
													inf->type != 'X')
			str[i] = inf->value_hex[g] + 32;
		else
			str[i] = inf->value_hex[g];
		i++;
		g--;
	}
	return (str);
}

int		hex_len(long int value, t_struct *inf)
{
	int i;

	i = 0;
	if (value == 0)
	{
		if (inf->plus && !inf->nv)
			i++;
		if (!inf->dack_prec || inf->sharp)
			i++;
		return (i);
	}
	else
	{
		if (inf->space && !inf->plus)
			i++;
		if (inf->plus)
			i++;
		if (inf->sharp && inf->type != 'o')
			i += 2;
		else if (inf->sharp && inf->type == 'o')
			i += 1;
	}
	i += inf->final_size;
	return (i);
}

void	ft_hexer(t_struct *inf, int flag)
{
	int i;

	i = 0;
	if (flag == 3)
		inf->value_d = (unsigned short)inf->value_d;
	else if (flag == 4)
		inf->value_d = (unsigned char)inf->value_d;
	else if (flag == 5)
		inf->value_d = (unsigned int)inf->value_d;
	while (inf->value_d >= 16)
	{
		if (inf->value_d % 16 < 10)
			inf->value_hex[i] = inf->value_d % 16 + '0';
		else
			inf->value_hex[i] = inf->value_d % 16 - 10 + 'A';
		inf->value_d /= 16;
		i++;
	}
	if (inf->value_d < 10)
		inf->value_hex[i] = inf->value_d + '0';
	else
		inf->value_hex[i] = inf->value_d - 10 + 'A';
	inf->final_size += i + 1;
}

int		ft_value_x(t_struct *inf, va_list list, int i)
{
	if (i == 1)
		inf->value_d = va_arg(list, unsigned long);
	else if (i == 2)
		inf->value_d = va_arg(list, unsigned long);
	else if (i == 3)
		inf->value_d = va_arg(list, unsigned int);
	else if (i == 4)
		inf->value_d = va_arg(list, int);
	else if (i == 5)
		inf->value_d = va_arg(list, unsigned long long int);
	ft_hexer(inf, i);
	return ((int)hex_len(inf->value_d, inf));
}
