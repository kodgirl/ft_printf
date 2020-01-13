/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:28:40 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/25 17:49:54 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_printf(const char *format, ...)
{
    va_list list;
    t_buff *buff_size;
    va_start(list, format);
    int i;

    i = 0;
    buff_size = ft_memalloc(sizeof(t_buff));
    //buff_size->flag = 1;
    while (*format)
    {
        if (*format == '%')
        {
            if (format[1] == '%')
            {
                format++;
                format += not_arg_searcher((char *)format, buff_size);
            }
            else
                format += ft_type((char *)format, list, buff_size);
        }
        else
            format += not_arg_searcher((char *)format, buff_size);
        format++;
    }
    va_end (list);
    i = buff_size->size_of_all;
    free(buff_size);
    return (i);
} 