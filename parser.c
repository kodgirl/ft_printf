/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:44:25 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/16 19:45:08 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_modifiers(char *format, t_struct *inf, t_buff\
								*buff_size, va_list list)
{
	int i;

	i = -1;
	while (++i < inf->givup)
	{
		if (format[i] == 'h')
		{
			if (format[i++ + 1] == 'h')
				inf->hh = 1;
			else
				inf->h = 1;
		}
		if (format[i] == 'l' || format[i] == 'L')
		{
			if (format[i++ + 1] == 'l')
				inf->ll = 1;
			else
				inf->l = 1;
		}
	}
	ft_value_maker(inf, buff_size, list);
	return (0);
}

int	ft_width(t_struct *inf, char *format, t_buff *buff_size, va_list list)
{
	int i;

	i = 0;
	while (i++ < inf->stop)
	{
		if (format[i] >= 49 && format[i] <= 57)
		{
			if (format[i - 1] == '-' || (inf->minus && inf->zero)\
										|| (inf->minus && inf->plus))
				inf->wg = 1;
			if ((inf->type == 'o' || inf->type == 'f') && inf->minus)
				inf->wg = 1;
			if (inf->wg)
				inf->zero = 0;
			inf->width = ft_new_atoi(format, i, inf->stop);
			if (inf->width > 0)
				break ;
		}
	}
	if (inf->p > inf->width)
		inf->zero = 0;
	ft_modifiers(format, inf, buff_size, list);
	return (0);
}

int	ft_precision(t_struct *inf, char *format,\
					t_buff *buff_size, va_list list)
{
	inf->givup = 0;
	while (inf->givup++ < inf->fuckup)
	{
		if (format[inf->givup] == '.')
		{
			inf->p = ft_new_atoi(format,\
					inf->givup + 1, inf->fuckup);
			if (inf->p == 0)
				inf->dack_prec = 2;
			inf->zero = ((inf->type == 's' || inf->type == 'f')\
													&& inf->zero) ? 1 : 0;
			inf->stop = inf->givup;
			inf->givup = inf->fuckup;
			ft_width(inf, format, buff_size, list);
			return (0);
		}
		inf->stop = inf->givup;
	}
	ft_width(inf, format, buff_size, list);
	return (0);
}

int	ft_flag(t_struct *inf, char *format, t_buff *buff_size, va_list list)
{
	int i;

	i = 0;
	while (i++ < inf->fuckup)
	{
		if (format[i] >= 49 && format[i] <= 57)
			break ;
		else if (format[i] == '+' && inf->type != 'u')
			inf->plus = 1;
		else if (format[i] == '-')
			inf->minus = 1;
		else if (format[i] == 32 && inf->type != 'u')
			inf->space = 1;
		else if (format[i] == 48)
			inf->zero = 1;
		else if (format[i] == 35 && inf->type != 'd')
			inf->sharp = 1;
	}
	if (inf->plus)
		inf->space = 0;
	ft_precision(inf, format, buff_size, list);
	return (0);
}

int	ft_type(char *format, va_list list, t_buff *buff_size)
{
	t_struct	*inf;

	inf = ft_memalloc(sizeof(t_struct));
	inf->fuckup = 0;
	while (format[inf->fuckup++])
	{
		if (ft_diouxx(inf, format[inf->fuckup]))
		{
			ft_flag(inf, (char *)format, buff_size, list);
			if (!(format[inf->fuckup + 1] == '\0'))
			{
				buff_size->test = 1;
				return (inf->fuckup);
			}
			if (format[inf->fuckup + 1] == '\0')
				return (inf->fuckup);
			break ;
		}
	}
	free(inf);
	return (0);
}
