/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_prec_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:10:03 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/26 13:30:45 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_text(char *format, int i, t_buff *buff_size)
{
    int g;
    char *str;
    
    g = 0;
    str = ft_memalloc(i + 2);
    while (g <= i)
    {
        str[g] = format[g];
        g++;
    }
    str[g] = '\0';
    write(1, str, ft_strlen(str));
    buff_size->size_of_all += g;
    free(str);
    return (0);
}

int not_arg_searcher(char *format, t_buff *buff_size)
{
    int i;

    i = 0;
    while (format[i + 1] != '%')
    {
        if (buff_size->test)
        {
            ft_text(format, i, buff_size);
            return (i);
        }
        if (format[i + 1] == '\0')
        {
            ft_text(format, i, buff_size);
            return (i);
        }
        i++;
    }
    ft_text(format, i, buff_size);
    buff_size->test = 0;
    return (i);
}
// выше функции для текста
char *start_by_len(t_struct *inform, char *buffer, int len)
{
    char *str;
    
    str = ft_memalloc(inform->final_size + 1);
    ft_flags(str, inform, 0, len);
    ft_strcat(str, buffer, inform);
    return (str);
}

char *start_by_prec(t_struct *inform, char *buffer, int len)
{
    char *str;
	int i;
	int g;

	g = 0;
	i = 0;
    str = ft_memalloc(inform->final_size + 1);
    if(ft_flags(str, inform, i, len))
    {
        i++;
        if ((inform->type == 'X' || inform->type == 'x') && inform->sharp)
        {
            i++;
            len--;
        }
        len--;
        if (inform->type == 'o')
            len++;
    }
    if (inform->type == 'p' && inform->precision > len)
    {
        while (g++ < inform->final_size - len)
            str[i++] = 48;
        ft_strpcat(str, inform, i);
    }
    else
    {
        while (g++ < inform->precision - len)
            str[i++] = 48;
        ft_strcat(str, buffer, inform);
    }
    return (str);
}