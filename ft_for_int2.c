/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_int2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:14:59 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/16 20:09:52 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*c_value_maker(t_struct *inf)
{
	char *str;

	str = ft_memalloc(inf->final_size + 1);
	str[0] = inf->value_hex[0];
	str[1] = '\0';
	return (str);
}

char	*x_value_maker(t_struct *inf)
{
	char *str;

	if (inf->h)
		str = hex_rev(inf);
	else if (inf->hh)
		str = hex_rev(inf);
	else if (inf->l)
		str = hex_rev(inf);
	else if (inf->ll)
		str = hex_rev(inf);
	else
		str = hex_rev(inf);
	return (str);
}

char	*o_value_maker(t_struct *inf)
{
	char *str;

	if (inf->h)
		str = hex_rev(inf);
	else if (inf->hh)
		str = hex_rev(inf);
	else if (inf->l)
		str = hex_rev(inf);
	else if (inf->ll)
		str = hex_rev(inf);
	else
		str = hex_rev(inf);
	return (str);
}

char	*u_value_maker(t_struct *inf)
{
	char *str;

	if (inf->h)
		str = ft_short_itoa((short)inf->value_d);
	else if (inf->hh)
		str = ft_new_itoa((unsigned char)inf->value_d);
	else if (inf->l)
		str = ft_long_itoa((long)inf->value_d);
	else if (inf->ll)
		str = ft_long_itoa((long long)inf->value_d);
	else
		str = ft_new_itoa(inf->value_d);
	return (str);
}

char	*d_value_maker(t_struct *inf)
{
	char *str;

	if (inf->h)
		str = ft_new_itoa((short)inf->value_d);
	else if (inf->hh)
		str = ft_new_itoa((char)inf->value_d);
	else if (inf->l)
		str = ft_new_itoa((long)inf->value_d);
	else if (inf->ll)
		str = ft_new_itoa((long long)inf->value_d);
	else
		str = ft_new_itoa(inf->value_d);
	return (str);
}
