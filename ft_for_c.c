/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:32:52 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/13 14:37:31 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	flag_clear(t_struct *inform)
{
	inform->plus = 0;
	inform->minus = 0;
	inform->space = 0;
	inform->sharp = 0;
	if (inform->type != '%')
		inform->zero = 0;
	inform->precision = 0;
	inform->dack_prec = 0;
}

int		ft_value_c(t_struct *inform, va_list list, int i)
{
	int len;

	len = 0;
	inform->value_hex[0] = va_arg(list, int);
	if (inform->value_hex[0] == '\0')
		inform->null_for_c = 1;
	if (inform->type == '%')
		inform->value_hex[0] = '%';
	inform->value_hex[0] = (unsigned char)inform->value_hex[0];
	flag_clear(inform);
	len += 1;
	return (len);
}
