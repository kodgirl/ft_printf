/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:32:52 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/16 20:28:27 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	flag_clear(t_struct *inf)
{
	inf->plus = 0;
	inf->minus = 0;
	inf->space = 0;
	inf->sharp = 0;
	if (inf->type != '%')
		inf->zero = 0;
	inf->p = 0;
	inf->dack_prec = 0;
}

int		ft_value_c(t_struct *inf, va_list list)
{
	int len;

	len = 0;
	inf->value_hex[0] = va_arg(list, int);
	if (inf->value_hex[0] == '\0')
		inf->null_for_c = 1;
	if (inf->type == '%')
		inf->value_hex[0] = '%';
	inf->value_hex[0] = (unsigned char)inf->value_hex[0];
	flag_clear(inf);
	len += 1;
	return (len);
}
