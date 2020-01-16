/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:56:04 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/16 16:19:20 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	list;
	t_buff	*buff_size;

	va_start(list, format);
	buff_size = ft_memalloc(sizeof(t_buff));
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
	va_end(list);
	free(buff_size);
	return (buff_size->size_of_all);
}
