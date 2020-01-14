/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:03:07 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/13 16:09:44 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_zeroes(char *s1, t_struct *inform, int len)
{
	int i;

	i = 0;
	if (ft_flags(s1, inform, i, len))
	{
		i++;
		if (inform->type == 'X' || (inform->type == 'x' && inform->sharp))
		{
			i++;
			len--;
		}
	}
	else
		len++;
	while (i <= inform->width - len)
		s1[i++] = '0';
	return (s1);
}

char	*ft_flags(char *str, t_struct *inform, int i, int len)
{
	if (inform->value_is_neg && (inform->type != 'u' && inform->type != 'o'))
	{
		if (inform->precision > len && !inform->zero && inform->precision > inform->width)
			inform->final_size += 1;
		str[i] = '-';
	}
	else if (inform->plus && !inform->value_is_neg)
	{
		if (inform->precision > len && inform->precision > inform->width)
			inform->final_size += 1;
		str[i] = '+';
	}
	else if (!inform->plus && !inform->value_is_neg && inform->space)
	{
		if (inform->precision > inform->width && inform->precision > len)
			inform->final_size += 1;
		else if (inform->value_d == 0 && !inform->width && !inform->nan_or_inf )
			inform->final_size += 1;
		str[i] = ' ';
	}
	else if (!inform->plus && !inform->value_is_neg && inform->sharp && inform->value_d != 0)
	{
		if (inform->precision > len && !inform->widthisneg && inform->width != 0 && inform->width > inform->precision)
			if (inform->type != 'X' && inform->type != 'x')
				return (str);
		str[i] = 48;
		if (inform->type == 'x' && inform->value_d != 0)
			str[++i] = 'x';
		if (inform->type == 'X' && inform->value_d != 0)
			str[++i] = 'X';
	}
	else
		return (0);
	return (str);
}

char	*ft_spacer(char *s1, char sym, t_struct *inform, int len)
{
	int i;

	i = 0;
	if (inform->precision > len)
	{
		if ((inform->type == 'x' || inform->type == 'X') && inform->sharp && inform->width > inform->precision && inform->precision != 0 && inform->value_d != 0)
			inform->precision += 1;
		while (i < inform->width - inform->precision)
			s1[i++] = sym;
		if (!ft_flags(s1, inform, i - 1, len))
		{
			inform->castilok = 1;
		}
	}
	else if (inform->width > len)
	{
		if (!inform->zero)
		{
			if ((inform->value_is_neg && inform->zero) || (inform->value_is_neg && inform->width - len == 1 && inform->type != 'f'))
				len++;
			if (inform->width - len == len && (inform->plus || inform->zero || inform->minus || inform->space))
				len++;
			while (i < inform->width - len)
				s1[i++] = sym;
			if (inform->width - len - inform->space == 1 && inform->value_d == 0)
				inform->space = 0;
			ft_flags(s1, inform, i, len);
		}
		else
			return (ft_zeroes(s1, inform, len));
	}
	return (0);
}

char	*ft_spacer_negative(char *s1, char sym, t_struct *inform)
{
	size_t i;
	size_t g;

	i = 0;
	g = 0;
	while (s1[i])
		i++;
	s1[inform->final_size] = '\0';
	while (i < inform->final_size)
		s1[i++] = sym;
	if (inform->type == 'c' && inform->null_for_c)
		s1[0] = '\0';
	return (s1);
}

char	*ft_negative_flags(char *str, t_struct *inform)
{
	if (inform->value_is_neg)
	{
		str[0] = '-';
		return (str);
	}
	else if (inform->plus && !inform->value_is_neg)
	{
		str[0] = '+';
		return (str);
	}
	else if (!inform->plus && !inform->value_is_neg && inform->space)
	{
		str[0] = ' ';
		return (str);
	}
	else if ((inform->type == 'o' || inform->type == 'X' || inform->type == 'x') && inform->sharp && !inform->dack_prec && inform->value_d != 0)
	{
		if (inform->value_d == 0)
			return (0);
		if (inform->type == 'X')
			str[1] = 'X';
		else if (inform->type == 'x')
			str[1] = 'x';
		str[0] = '0';
		return (str);
	}
	return (0);
}
