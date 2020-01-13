/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:52:40 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/21 14:41:07 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int us_int_len(unsigned short int value, t_struct *inform)
{
    int i;
	
    i = 0;
	if (value == 0)
	{
		if (inform->plus && !inform->value_is_neg)
			i++;
		if (!inform->dack_prec)
			i++;
		return(i);
	}
    else 
    {
		if (inform->space && !inform->plus)
			i++;
        if (inform->plus)
            i++;
    }
    while (value != 0)
    {
        value /= 10;
        i++;
    }
    return(i);
}

int ul_int_len(unsigned long int value, t_struct *inform)
{
    int i;
	
    i = 0;
	if (value == 0)
	{
		if (inform->plus && !inform->value_is_neg)
			i++;
		if (!inform->dack_prec)
			i++;
		return(i);
	}
    else 
    {
		if (inform->space && !inform->plus)
			i++;
        if (inform->plus || inform->sharp)
            i++;
    }
    while (value != 0)
    {
        value /= 10;
        i++;
    }
    return(i);
}

int int_len(long int value, t_struct *inform)
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
    if (value < 0)
	{
        i++;
		inform->value_is_neg = 1;
	}
    else 
    {
		if ((inform->space && !inform->plus) || inform->sharp)
			i++;
        if (inform->plus)
            i++;
    }
    while (value != 0)
    {
        value /= 10;
        i++;
    }
    return(i);
}

int ft_value_u(t_struct *inform, va_list list, int i)
{
    int len;
    len = 0;
    if (i == 1)
    {
    	inform->value_d = va_arg(list, unsigned long);
		len = ul_int_len(inform->value_d, inform);
    }
	else if (i == 2)
    {
        inform->value_d = va_arg(list, unsigned long);
		len = ul_int_len(inform->value_d, inform);
    }
	else if (i == 3)
    {
        inform->value_d = va_arg(list, unsigned int);
		len = us_int_len((short)inform->value_d, inform);
    }
	else if (i == 4)
    {
        inform->value_d = va_arg(list, unsigned int);
		len = us_int_len((unsigned char)inform->value_d, inform);
    }
	if (i == 5)
    {
        inform->value_d = va_arg(list, unsigned int);
		len = int_len(inform->value_d, inform);
    }
    return (len);
}

int ft_value_d(t_struct *inform, va_list list, int i)
{
    int len;

    len = 0;
    if (i == 1)
    {
    	inform->value_d = va_arg(list, long int);
		len = int_len((long)inform->value_d, inform);
    }
	else if (i == 2)
    {
        inform->value_d = va_arg(list, long long);
		len = int_len(inform->value_d, inform);
    }
	else if (i == 3)
    {
        inform->value_d = va_arg(list, int);
		len = int_len((short)inform->value_d, inform);
    }
	else if (i == 4)
    {
        inform->value_d = va_arg(list, int);
		len = int_len((char)inform->value_d, inform);
    }
	if (i == 5)
    {
        inform->value_d = va_arg(list, int);
		len = int_len(inform->value_d, inform);
    }
    return (len);
}