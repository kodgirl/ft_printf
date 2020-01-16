/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:03:07 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/16 17:28:15 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_zeroes(char *s1, t_struct *inf, int len)
{
	int i;

	i = 0;
	if (ft_flags(s1, inf, i, len))
	{
		i++;
		if (inf->type == 'X' || (inf->type == 'x' && inf->sharp))
		{
			i++;
			len--;
		}
	}
	else
		len++;
	while (i <= inf->width - len)
		s1[i++] = '0';
	return (s1);
}

char	*ft_flags(char *str, t_struct *inf, int i, int len)
{
	if (inf->value_is_neg && (inf->type != 'u' && inf->type != 'o'))
	{
		if (inf->precision > len && !inf->zero && inf->precision > inf->width)
			inf->final_size += 1;
		str[i] = '-';
	}
	else if (inf->plus && !inf->value_is_neg)
	{
		if (inf->precision > len && inf->precision > inf->width)
			inf->final_size += 1;
		str[i] = '+';
	}
	else if (!inf->plus && !inf->value_is_neg && inf->space)
	{
		if ((inf->precision > inf->width && inf->precision > len) || (inf->value_d == 0 && !inf->width && !inf->nan_or_inf))
			inf->final_size += 1;
		str[i] = ' ';
	}
	else if (!inf->plus && !inf->value_is_neg && inf->sharp && inf->value_d != 0)
	{
		if (inf->precision > len && !inf->widthisneg && inf->width != 0 && inf->width > inf->precision)
			if (inf->type != 'X' && inf->type != 'x')
				return (str);
		str[i] = 48;
		if ((inf->type == 'x' && inf->value_d != 0) || (inf->type == 'X' && inf->value_d != 0))
			str[++i] = inf->type;
	}
	else
		str = 0;
	return (str);
}

char	*ft_spacer(char *s1, char sym, t_struct *inf, int len)
{
	int i;

	i = 0;
	if (inf->precision > len)
	{
		if ((inf->type == 'x' || inf->type == 'X') && inf->sharp && inf->width > inf->precision && inf->precision != 0 && inf->value_d != 0)
			inf->precision += 1;
		while (i < inf->width - inf->precision)
			s1[i++] = sym;
		inf->castilok = (!ft_flags(s1, inf, i - 1, len)) ? 1 : 0;
	}
	else if (inf->width > len)
	{
		if (!inf->zero)
		{
			if ((inf->value_is_neg && inf->zero) || (inf->value_is_neg && inf->width - len == 1 && inf->type != 'f') || (inf->width - len == len && (inf->plus || inf->zero || inf->minus || inf->space)))
				len++;
			while (i < inf->width - len)
				s1[i++] = sym;
			if (inf->width - len - inf->space == 1 && inf->value_d == 0)
				inf->space = 0;
			ft_flags(s1, inf, i, len);
		}
		else
			return (ft_zeroes(s1, inf, len));
	}
	return (0);
}

char	*ft_spacer_negative(char *s1, char sym, t_struct *inf)
{
	size_t i;
	size_t g;

	i = 0;
	g = 0;
	while (s1[i])
		i++;
	s1[inf->final_size] = '\0';
	while (i < inf->final_size)
		s1[i++] = sym;
	if (inf->type == 'c' && inf->null_for_c)
		s1[0] = '\0';
	return (s1);
}

char	*ft_negative_flags(char *str, t_struct *inf)
{
	if (inf->value_is_neg)
		str[0] = '-';
	else if (inf->plus && !inf->value_is_neg)
		str[0] = '+';
	else if (!inf->plus && !inf->value_is_neg && inf->space)
		str[0] = ' ';
	else if ((inf->type == 'o' || inf->type == 'X' || inf->type == 'x')\
	&& inf->sharp && !inf->dack_prec && inf->value_d != 0)
	{
		if (inf->value_d == 0)
			return (0);
		if (inf->type == 'X')
			str[1] = 'X';
		else if (inf->type == 'x')
			str[1] = 'x';
		str[0] = '0';
	}
	else
		str = 0;
	return (str);
}
