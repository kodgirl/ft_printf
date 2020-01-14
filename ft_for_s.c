/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:17:03 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/14 16:24:04 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_minus_widther(t_struct *inform, char *buffer, int len)
{
	int		i;
	int		g;
	char	*str;

	g = 0;
	i = 0;
	str = ft_memalloc(inform->width + 1);
	ft_strcat(str, buffer, inform);
	while (str[i] != '\0')
		i++;
	while (g++ < inform->width - inform->s_len)
		str[i++] = ' ';
	return (str);
}

char	*ft_widther(t_struct *inform, char *buffer, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_memalloc(inform->width + 1);
	if (inform->dack_prec)
	{
		while (i < inform->width)
			str[i++] = (inform->zero) ? '0' : ' ';
		return (str);
	}
	else
	{
		while (i < inform->width - inform->s_len)
			str[i++] = (inform->zero) ? '0' : ' ';
		str = ft_strcat(str, buffer, inform);
	}
	return (str);
}

char	*str_maker(t_struct *inform, char *buffer, int len)
{
	char *str;

	if (inform->width > inform->s_len && !inform->minus)
	{
		str = ft_widther(inform, buffer, len);
		return (str);
	}
	else if (inform->width > inform->s_len && inform->minus)
	{
		str = ft_minus_widther(inform, buffer, len);
		return (str);
	}
	return (buffer);
}

char	*s_value_maker(t_struct *inform, char *buffer)
{
	char *str;

	if (inform->precision < inform->s_len)
	{
		str = ft_memalloc(inform->final_size + 1);
		ft_strfncat(str, inform->govno, inform->final_size);
	}
	else
	{
		str = ft_memalloc(inform->s_len + 1);
		ft_strfncat(str, inform->govno, inform->s_len);
	}
	return (str);
}

int		ft_value_s(t_struct *inform, va_list list, int i)
{
	int		len;
	char	*str;

	len = 0;
	str = va_arg(list, char *);
	str = (char *)str;
	if (str == NULL)
		inform->govno = "(null)";
	else
		inform->govno = str;
	len = ft_strlen(inform->govno);
	if (inform->precision < len && inform->precision != 0)
		inform->s_len = inform->precision;
	else
		inform->s_len = len;
	if (inform->dack_prec && inform->precision < len)
		inform->s_len = inform->precision;
	if (inform->width > inform->s_len)
		inform->final_size += inform->width;
	else
		inform->final_size += inform->s_len;
	return (len);
}
