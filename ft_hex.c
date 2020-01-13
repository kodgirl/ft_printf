/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:38:08 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/25 14:39:16 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *hex_rev(t_struct *inform)
{
    int i;
    int g;
    char *str;
    
    i = 0;
    g = 0;
    while (inform->value_hex[g + 1] != '\0')
        g++;
    str = ft_memalloc(g + 2);
    while (g >= 0)
    {
        if (inform->value_hex[g] >= 65 && inform->value_hex[g] <= 90 && inform->type != 'X')
            str[i] = inform->value_hex[g] + 32;
        else
            str[i] = inform->value_hex[g];
        i++;
        g--;
    }
    return(str);
}

int hex_len(long int value, t_struct *inform)
{
    int i;
	
    i = 0;
	if (value == 0)
	{
		if (inform->plus && !inform->value_is_neg)
			i++;
		if (!inform->dack_prec || inform->sharp)
			i++;
		return(i);
	}
    else 
    {
		if (inform->space && !inform->plus)
			i++;
        if (inform->plus)
            i++;
        if (inform->sharp && inform->type != 'o')
            i += 2;
        else if (inform->sharp && inform->type == 'o')
            i += 1;
    }
    i += inform->final_size;
    return(i);
}

void ft_hexer(t_struct *inform, int flag)
{
    int i;

    i = 0;
    if (flag == 3)
        inform->value_d = (unsigned short)inform->value_d;
    else if (flag == 4)
        inform->value_d = (unsigned char)inform->value_d;
    else if (flag == 5)
        inform->value_d = (unsigned int)inform->value_d;
    while (inform->value_d >= 16)
    {
        inform->value_hex[i] = (inform->value_d % 16 < 10) ? inform->value_d % 16 + '0' : inform->value_d % 16 - 10 + 'A';
        inform->value_d /= 16;
        i++;
    }
    inform->value_hex[i] = (inform->value_d < 10) ? inform->value_d + '0' : inform->value_d - 10 + 'A';
    inform->final_size += i + 1;
}

int ft_value_x(t_struct *inform, va_list list, int i)
{
    int len;
    
    len = 0;
    if (i == 1)
    {
    	inform->value_d = va_arg(list, unsigned long);
        ft_hexer(inform, 1);
		len = hex_len(inform->value_d, inform);
    }
	else if (i == 2)
    {
        inform->value_d = va_arg(list, unsigned long);
        ft_hexer(inform, 2);
		len = hex_len(inform->value_d, inform);
    }
	else if (i == 3)
    {
        inform->value_d = va_arg(list, unsigned int);
        ft_hexer(inform, 3);
		len = hex_len(inform->value_d, inform);
    }
	else if (i == 4)
    {
        inform->value_d = va_arg(list, int);
        ft_hexer(inform, 4);
		len = hex_len(inform->value_d, inform);
    }
	if (i == 5)
    {
        inform->value_d = va_arg(list, unsigned long long int);
        ft_hexer(inform, 5);
		len = hex_len(inform->value_d, inform);
    }
    return (len);
}