/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:56:33 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/13 16:26:12 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*f_value_maker(t_struct *infrom, char *buffer)
{
	return (infrom->govno);
}

int		f_len(t_struct *inform)
{
	int len;

	len = 0;
	len = ft_strlen(inform->govno);
	if (inform->plus == 1 || inform->value_f < 0)
	{
		inform->value_is_neg = (inform->value_f < 0) ? 1 : 0;
		len += 1;
	}
	if (inform->space && (!inform->minus && inform->value_f > 0))
		len += 1;
	if (inform->space && (inform->minus && inform->value_f > 0))
		len += 1;
	if (inform->value_is_neg && inform->value_f == -0 && !inform->nan_or_inf)
		len += 1;
	return (len);
}

int		ft_value_f(t_struct *inform, va_list list, int i)
{
    int		len;
	char	*str;
	
	len = 0;
    inform->value_f = (inform->l) ? va_arg(list, long double) : va_arg(list, double);
	inform->govno = ft_float(inform->value_f, inform);
	len = f_len(inform);
	return (len);
}
