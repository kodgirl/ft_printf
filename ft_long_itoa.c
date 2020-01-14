/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:02:54 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/14 16:52:46 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_long_len(unsigned long int f)
{
	int		i;

	i = 0;
	if (f == 0)
	{
		i = 1;
		return (i);
	}
	while (f)
	{
		f = f / 10;
		i++;
	}
	return (i);
}

char	*ft_long_final(unsigned long int f)
{
	int		len;
	char	*tmp;

	len = ft_long_len(f);
	if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	tmp[len] = '\0';
	len = len - 1;
	while (len >= 0)
	{
		tmp[len--] = f % 10 + 48;
		f = f / 10;
	}
	return (tmp);
}

char	*ft_long_itoa(unsigned long int n)
{
	char	*res;
	long	nbr;

	nbr = n;
	res = ft_long_final(nbr);
	return (res);
}

char	*ft_short_itoa(unsigned short int n)
{
	char	*res;
	long	nbr;

	nbr = n;
	res = ft_long_final(nbr);
	return (res);
}
