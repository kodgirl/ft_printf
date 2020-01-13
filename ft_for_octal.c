/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:56:48 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/21 14:14:02 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

void ft_octal(t_struct *inform, int flag)
{
    int i;

    i = 0;
    if (flag == 3)
        inform->value_d = (unsigned short)inform->value_d;
    else if (flag == 4)
        inform->value_d = (unsigned char)inform->value_d;
    else if (flag == 5)
        inform->value_d = (unsigned int)inform->value_d;
    while (inform->value_d >= 8)
    {
        inform->value_hex[i] = inform->value_d % 8 + '0';
        inform->value_d /= 8;
        i++;
    }
    inform->value_hex[i] = inform->value_d + '0';
    inform->final_size += i + 1;
}

int ft_value_o(t_struct *inform, va_list list, int i)
{
    int len;

    len = 0;
    if (i == 1)
    {
    	inform->value_d = va_arg(list, unsigned long);
        ft_octal(inform, 1);
		len = hex_len(inform->value_d, inform);
    }
	else if (i == 2)
    {
        inform->value_d = va_arg(list, unsigned long);
        ft_octal(inform, 2);
		len = hex_len(inform->value_d, inform);
    }
	else if (i == 3)
    {
        inform->value_d = va_arg(list, unsigned int);
        ft_octal(inform, 3);
		len = hex_len(inform->value_d, inform);
    }
	else if (i == 4)
    {
        inform->value_d = va_arg(list, int);
        ft_octal(inform, 4);
		len = hex_len(inform->value_d, inform);
    }
	if (i == 5)
    {
        inform->value_d = va_arg(list, unsigned long long int);
        ft_octal(inform, 5);
		len = hex_len(inform->value_d, inform);
    }
    return (len);
}