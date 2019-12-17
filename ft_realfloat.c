/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realfloat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 20:24:23 by bjasper           #+#    #+#             */
/*   Updated: 2019/12/17 15:30:40 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr(intmax_t nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
		ft_putchar(nb + 48);
}

void     ft_realfloat(long double nb)
{
    intmax_t a;
    int flag;
    int i;
    char *str;
    
    flag = 10;
    i = 0;
    str = ft_itoa(nb);
    str = ft_strjoin(str, ".");
    nb -= (intmax_t)nb;
    while (nb != 0)
    {
        nb *= 10;
        str = ft_strjoin(str, ft_itoa((intmax_t)nb % 10));
        nb -= (intmax_t)nb;
    }
    ft_putstr(str);  
}

int main()
{
    long double nb;
    intmax_t a;

    // nb = __LDBL_MAX__;
    nb = 467456897845568.34389776545649;
    printf("%Lf\n", nb);
    ft_realfloat(nb);
    return (0);
}