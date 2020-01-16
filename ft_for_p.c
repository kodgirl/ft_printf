/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:12:15 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/16 15:02:05 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*p_value_maker(t_struct *infrom, char *buffer)
{
	char *str;

	str = ft_memalloc(infrom->final_size + 1);
	str[0] = 48;
	str[1] = 'x';
	if (infrom->value_d == 0 && infrom->dack_prec)
		infrom->govno[0] = '\0';
	ft_strcat(str, infrom->govno, infrom);
	return (str);
}

int		ft_value_p(t_struct *inf, va_list list, int i)
{
	int		len;
	char	*str;

	len = 0;
	inf->value_d = va_arg(list, intptr_t);
	ft_hexer(inf, 0);
	str = hex_rev(inf);
	len = ft_strlen(str);
	inf->govno = str;
	if (inf->value_d == 0 && inf->dack_prec)
		return (len + 1);
	return (len + 2);
}
