/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:12:19 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/16 20:32:40 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	width_and_precision(t_struct *inf, int len)
{
	if (inf->type == 's')
		return ;
	if (inf->width > inf->p)
		inf->final_size = inf->width;
	else
	{
		inf->final_size = inf->p;
		if ((inf->type == 'X' || inf->type == 'x') &&\
						inf->sharp && inf->value_d != 0)
			inf->final_size += 2;
	}
	if (inf->final_size < len)
		inf->final_size = len;
	inf->final_size = (inf->type == 'p' && inf->p > len)\
								? inf->p + 2 : inf->final_size;
}

int		flag_corrector(t_struct *inf)
{
	if (inf->ll == 1)
	{
		inf->l = 0;
		inf->h = 0;
		inf->h = 0;
		return (1);
	}
	if (inf->l == 1)
	{
		inf->h = 0;
		inf->hh = 0;
		return (2);
	}
	if (inf->h == 1)
	{
		inf->hh = 0;
		return (3);
	}
	if (inf->hh == 1)
		return (4);
	return (5);
}

int		va_value(t_struct *inf, va_list list, int i)
{
	int len;

	len = 0;
	if (inf->type == 'd')
		len = ft_value_d(inf, list, i);
	else if (inf->type == 'u')
		len = ft_value_u(inf, list, i);
	else if (inf->type == 'o')
		len = ft_value_o(inf, list, i);
	else if (inf->type == 'x' || inf->type == 'X')
		len = ft_value_x(inf, list, i);
	else if (inf->type == 'c' || inf->type == '%')
		len = ft_value_c(inf, list);
	else if (inf->type == 's')
		len = ft_value_s(inf, list);
	else if (inf->type == 'p')
		len = ft_value_p(inf, list);
	else if (inf->type == 'f')
		len = ft_value_f(inf, list);
	return (len);
}

void	ft_make_arg(t_struct *inf, int len)
{
	char *buffer;
	char *str;

	buffer = NULL;
	buffer = value_maker(inf);
	if (inf->type != 's')
		str = word_maker(inf, buffer, len);
	else
		str = str_maker(inf, buffer);
	write(1, str, inf->final_size);
	if (!inf->nan_or_inf)
		free(buffer);
	if (inf->type != 's')
		free(str);
	if (inf->type == 'p')
		free(inf->govno);
}

int		ft_value_maker(t_struct *inf, t_buff *buff_size, va_list list)
{
	size_t	len;
	int		i;

	len = 0;
	i = flag_corrector(inf);
	len = va_value(inf, list, i);
	width_and_precision(inf, len);
	ft_make_arg(inf, len);
	buff_size->size_of_all += inf->final_size;
	free(inf);
	return (0);
}
