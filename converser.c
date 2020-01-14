/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:02:37 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/13 16:52:12 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strpcat(char *s1, t_struct *inform, int len)
{
	int i;
	int g;

	i = 0;
	g = 2;
	s1[0] = '0';
	s1[1] = 'x';
	while (i++ < len)
		s1[g++] = '0';
	ft_strcat(s1, inform->govno, inform);
	return (s1);
}

char	*ft_strfromcat(char *s1, const char *s2, size_t len, size_t n)
{
	size_t i;
	size_t g;
	size_t s;

	s = 0;
	i = 0;
	g = n;
	while (s1[i] != '\0')
		i++;
	s1[i] = s2[g];
	while (s2[g] != '\0' && s < len)
	{
		s1[i] = s2[g];
		i++;
		g++;
		s++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strfncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t g;

	i = 0;
	g = 0;
	while (s1[i] != '\0')
		i++;
	s1[i] = s2[g];
	while (s2[g] != '\0' && g < n)
	{
		s1[i] = s2[g];
		i++;
		g++;
	}
	s1[i] = '\0';
	return (s1);
}

int		ft_new_atoi(const char *str, int start, int end)
{
	int				i;
	long long int	nbr;

	i = start;
	nbr = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && i < end)
		nbr = 10 * nbr + (str[i++] - '0');
	return (nbr);
}
