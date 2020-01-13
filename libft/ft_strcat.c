/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:41:57 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/10 18:34:16 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2, char dack)
{
	size_t i;
	size_t g;

	i = 0;
	g = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[g] != '\0')
	{
		s1[i] = s2[g];
		g++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}