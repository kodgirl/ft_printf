/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:32:14 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/16 20:26:57 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_spacer_p2(char *s1, int i, t_struct *j, int len)
{
	if ((j->nv && j->zero) || (j->nv && j->width - len == 1 && j->type != 'f')\
	|| (j->width - len == len && (j->plus || j->zero || j->minus || j->space)))
		len++;
	while (i < j->width - len)
		s1[i++] = 32;
	if (j->width - len - j->space == 1 && j->value_d == 0)
		j->space = 0;
	ft_flags(s1, j, i, len);
}

char	*ft_flags1(char *str, t_struct *inf, int i, int len)
{
	if (inf->p > len && !inf->wg && inf->width != 0 && inf->width > inf->p)
		if (inf->type != 'X' && inf->type != 'x')
			return (str);
	str[i] = 48;
	if ((inf->type == 'x' && inf->value_d != 0)\
	|| (inf->type == 'X' && inf->value_d != 0))
		str[++i] = inf->type;
	return (str);
}

void	ft_octal(t_struct *inf, int flag)
{
	int i;

	i = 0;
	if (flag == 3)
		inf->value_d = (unsigned short)inf->value_d;
	else if (flag == 4)
		inf->value_d = (unsigned char)inf->value_d;
	else if (flag == 5)
		inf->value_d = (unsigned int)inf->value_d;
	while (inf->value_d >= 8)
	{
		inf->value_hex[i] = inf->value_d % 8 + '0';
		inf->value_d /= 8;
		i++;
	}
	inf->value_hex[i] = inf->value_d + '0';
	inf->final_size += i + 1;
}

int		ft_value_o(t_struct *inf, va_list list, int i)
{
	if (i == 1)
		inf->value_d = va_arg(list, unsigned long);
	else if (i == 2)
		inf->value_d = va_arg(list, long long);
	else if (i == 3)
		inf->value_d = va_arg(list, unsigned int);
	else if (i == 4)
		inf->value_d = va_arg(list, int);
	if (i == 5)
		inf->value_d = va_arg(list, unsigned long long int);
	ft_octal(inf, i);
	return (hex_len(inf->value_d, inf));
}
