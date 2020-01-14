/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:03:29 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/14 16:54:25 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_len(long f)
{
	int		i;

	i = 0;
	if (f == 0)
	{
		i = 1;
		return (i);
	}
	if (f < 0)
		f *= (-1);
	while (f)
	{
		f = f / 10;
		i++;
	}
	return (i);
}

char		*ft_final(long int f)
{
	int		len;
	char	*tmp;

	len = ft_len(f);
	if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	tmp[len] = '\0';
	len = len - 1;
	if (f < 0)
		f = f * -1;
	while (len >= 0)
	{
		if (f < 0)
		{
			tmp[len--] = f % 10 * (-1) + 48;
			f = f / 10;
		}
		else
		{
			tmp[len--] = f % 10 + 48;
			f = f / 10;
		}
	}
	return (tmp);
}

char		*ft_new_itoa(long int n)
{
	char	*res;
	long	nbr;

	nbr = n;
	res = ft_final(nbr);
	return (res);
}

char		*ft_oct_itoa(long int n)
{
	char		*res;
	long int	nbr;

	nbr = n;
	res = ft_final(nbr);
	return (res);
}
