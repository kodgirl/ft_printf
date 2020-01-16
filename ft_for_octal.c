/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:32:14 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/16 15:02:05 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
