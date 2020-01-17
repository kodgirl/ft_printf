/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:56:33 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/16 20:36:41 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_for_float(t_str *ind, char *str, t_struct *flags, t_float *number)
{
	while (ind->j <= flags->p)
	{
		str[ind->i] = number->fract[MAX_FRACT_SIZE - ind->j] + '0';
		++ind->j;
		++ind->i;
	}
	--ind->i;
	if (number->fract[MAX_FRACT_SIZE - ind->j] + 48 >= '5')
	{
		if (str[ind->i] < '9' && str[ind->i] != '.')
			str[ind->i] += 1;
		else
			while (str[ind->i] == '9' && str[ind->i] != '.')
			{
				if (str[ind->i - 1] == '.')
					str[ind->i - 2] += 1;
				str[ind->i] = '0';
				if (str[ind->i - 1] != '9' && str[ind->i - 1] != '.')
				{
					str[ind->i - 1] += 1;
					break ;
				}
				--ind->i;
			}
	}
}

char	*f_value_maker(t_struct *infrom)
{
	return (infrom->govno);
}

int		f_len(t_struct *inf)
{
	int len;

	len = 0;
	len = ft_strlen(inf->govno);
	if (inf->plus == 1 || inf->value_f < 0)
	{
		inf->nv = (inf->value_f < 0) ? 1 : 0;
		len += 1;
	}
	if (inf->space && (!inf->minus && inf->value_f > 0))
		len += 1;
	if (inf->space && (inf->minus && inf->value_f > 0))
		len += 1;
	if (inf->nv && inf->value_f == -0 && !inf->nan_or_inf)
		len += 1;
	return (len);
}

int		ft_value_f(t_struct *inf, va_list list)
{
	int		len;

	len = 0;
	inf->value_f = (inf->l) ? va_arg(list, long double)\
										: va_arg(list, double);
	inf->govno = ft_float(inf->value_f, inf);
	len = f_len(inf);
	return (len);
}
