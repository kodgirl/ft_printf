/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_width_maker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:09:46 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/16 17:42:47 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*start_by_neg_width(t_struct *inf, char *buffer, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_memalloc(inf->final_size + 1);
	if (ft_negative_flags(str, inf))
	{
		i++;
		len -= 2;
		len += (inf->type == 'o') ? 1 : 0;
		if ((inf->type == 'X' || inf->type == 'x') && inf->sharp && i++)
			len -= 2;
	}
	len *= (len < 0 && inf->type == 'o') ? -1 : 1;
	len = (len < 0) ? 0 : len;
	if (inf->precision > len)
	{
		while (i < inf->precision - (len))
			str[i++] = '0';
	}
	ft_strcat(str, buffer, inf);
	ft_spacer_negative(str, ' ', inf);
	return (str);
}

char	*start_by_width(t_struct *inf, char *buffer, int len)
{
	char	*str;
	int		i;
	int		g;

	g = 0;
	i = 0;
	if (inf->widthisneg)
		str = start_by_neg_width(inf, buffer, len);
	else
	{
		str = ft_memalloc(inf->final_size + 1);
		if ((ft_spacer(str, ' ', inf, len) == NULL) && !inf->castilok)
			len -= (len != inf->precision || inf->space\
				|| inf->value_is_neg || inf->plus) ? 1 : 0;
		while (str[i])
			i++;
		if (inf->precision >= len)
		{
			while (g++ < inf->precision - len)
				str[i++] = 48;
		}
		ft_strcat(str, buffer, inf);
	}
	return (str);
}

char	*word_maker(t_struct *inf, char *buffer, int len)
{
	char	*str;
	int		i;

	i = 0;
	if (inf->width > inf->precision && inf->width > len)
		str = start_by_width(inf, buffer, len);
	else if (inf->precision >= inf->width && inf->precision > len)
		str = start_by_prec(inf, buffer, len);
	else
		str = start_by_len(inf, buffer, len);
	return (str);
}

char	*value_maker(t_struct *inf, char *buffer)
{
	char *str;

	if (inf->type == 'd')
		str = d_value_maker(inf, buffer);
	else if (inf->type == 'u')
		str = u_value_maker(inf, buffer);
	else if (inf->type == 'o')
		str = o_value_maker(inf, buffer);
	else if (inf->type == 'x' || inf->type == 'X')
		str = x_value_maker(inf, buffer);
	else if (inf->type == 'c' || inf->type == '%')
		str = c_value_maker(inf, buffer);
	else if (inf->type == 's')
		str = s_value_maker(inf, buffer);
	else if (inf->type == 'p')
		str = p_value_maker(inf, buffer);
	else
		str = f_value_maker(inf, buffer);
	return (str);
}
