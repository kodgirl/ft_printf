/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:03:07 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/16 20:40:13 by rgwayne-         ###   ########.fr       */
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
	if (inf->nv && (inf->type != 'u' && inf->type != 'o'))
	{
		if (inf->p > len && !inf->zero && inf->p > inf->width)
			inf->final_size += 1;
		str[i] = '-';
	}
	else if (inf->plus && !inf->nv)
	{
		if (inf->p > len && inf->p > inf->width)
			inf->final_size += 1;
		str[i] = '+';
	}
	else if (!inf->plus && !inf->nv && inf->space)
	{
		if ((inf->p > inf->width && inf->p > len)\
			|| (inf->value_d == 0 && !inf->width && !inf->nan_or_inf))
			inf->final_size += 1;
		str[i] = ' ';
	}
	else if (!inf->plus && !inf->nv && inf->sharp && inf->value_d != 0)
		ft_flags1(str, inf, i, len);
	else
		str = 0;
	return (str);
}

char	*ft_spacer(char *s1, char sym, t_struct *j, int len)
{
	int i;

	i = 0;
	if (j->p > len)
	{
		if ((j->type == 'x' || j->type == 'X')\
		&& j->sharp && j->width > j->p && j->p != 0 && j->value_d != 0)
			j->p += 1;
		while (i < j->width - j->p)
			s1[i++] = sym;
		j->castilok = (!ft_flags(s1, j, i - 1, len)) ? 1 : 0;
	}
	else if (j->width > len)
	{
		if (!j->zero)
		{
			ft_spacer_p2(s1, i, j, len);
		}
		else
			return (ft_zeroes(s1, j, len));
	}
	return (0);
}

char	*ft_spacer_negative(char *s1, char sym, t_struct *inf)
{
	int		i;
	size_t	g;

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
	if (inf->nv)
		str[0] = '-';
	else if (inf->plus && !inf->nv)
		str[0] = '+';
	else if (!inf->plus && !inf->nv && inf->space)
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
