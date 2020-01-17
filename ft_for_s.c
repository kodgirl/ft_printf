/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:17:03 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/16 20:33:54 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_minus_widther(t_struct *inf, char *buffer)
{
	int		i;
	int		g;
	char	*str;

	g = 0;
	i = 0;
	str = ft_memalloc(inf->width + 1);
	ft_strcat(str, buffer, inf);
	while (str[i] != '\0')
		i++;
	while (g++ < inf->width - inf->s_len)
		str[i++] = ' ';
	return (str);
}

char	*ft_widther(t_struct *inf, char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_memalloc(inf->width + 1);
	if (inf->dack_prec)
	{
		while (i < inf->width)
			str[i++] = (inf->zero) ? '0' : ' ';
		return (str);
	}
	else
	{
		while (i < inf->width - inf->s_len)
			str[i++] = (inf->zero) ? '0' : ' ';
		str = ft_strcat(str, buffer, inf);
	}
	return (str);
}

char	*str_maker(t_struct *inf, char *buffer)
{
	char *str;

	if (inf->width > inf->s_len && !inf->minus)
	{
		str = ft_widther(inf, buffer);
		return (str);
	}
	else if (inf->width > inf->s_len && inf->minus)
	{
		str = ft_minus_widther(inf, buffer);
		return (str);
	}
	return (buffer);
}

char	*s_value_maker(t_struct *inf)
{
	char *str;

	if (inf->p < inf->s_len)
	{
		str = ft_memalloc(inf->final_size + 1);
		ft_strfncat(str, inf->govno, inf->final_size);
	}
	else
	{
		str = ft_memalloc(inf->s_len + 1);
		ft_strfncat(str, inf->govno, inf->s_len);
	}
	return (str);
}

int		ft_value_s(t_struct *inf, va_list list)
{
	int		len;
	char	*str;

	len = 0;
	str = va_arg(list, char *);
	str = (char *)str;
	if (str == NULL)
		inf->govno = "(null)";
	else
		inf->govno = str;
	len = ft_strlen(inf->govno);
	if (inf->p < len && inf->p != 0)
		inf->s_len = inf->p;
	else
		inf->s_len = len;
	if (inf->dack_prec && inf->p < len)
		inf->s_len = inf->p;
	if (inf->width > inf->s_len)
		inf->final_size += inf->width;
	else
		inf->final_size += inf->s_len;
	return (len);
}
