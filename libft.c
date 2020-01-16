/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:04:09 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/16 16:07:24 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return ((unsigned char *)b);
}

void	*ft_memalloc(size_t size)
{
	char *arr;

	if (size > 0)
	{
		arr = (void *)malloc(sizeof(unsigned char) * size);
		if (arr == 0)
			return (NULL);
		else
		{
			ft_bzero(arr, size);
			return (arr);
		}
	}
	else
		return (NULL);
}

void	ft_for_strcat(t_cat *cat, char *s1, const char *s2, t_struct *inf)
{
	if (s2[cat->g] == 48 && inf->dack_prec == 1 && inf->sharp == 0)
	{
		s1[cat->i++] = ' ';
		cat->g++;
	}
	s1[cat->i] = s2[cat->g];
	if (s2[cat->g] == 48 && inf->dack_prec == 2 && inf->sharp == 0\
												&& inf->type != 'p')
	{
		if ((inf->value_d == 0 && inf->type != 'f') || (inf->value_d == 0\
								&& (inf->type == 'x' || inf->type == 'X')))
			s1[cat->i] = ' ';
	}
	else if (s2[cat->g] == 48 && inf->dack_prec == 2 && inf->sharp == 1 &&\
						inf->width && (inf->type == 'x' || inf->type == 'X'))
		s1[cat->i] = ' ';
	else if (s2[cat->g] == 48 && inf->dack_prec == 2 && inf->sharp == 1 &&\
						!inf->width && (inf->type == 'x' || inf->type == 'X'))
	{
		inf->final_size -= 1;
		s1[cat->i] = '\0';
	}
	cat->g++;
	cat->i++;
}

char	*ft_strcat(char *s1, const char *s2, t_struct *inf)
{
	t_cat	cat;

	cat.i = 0;
	cat.g = 0;
	while (s1[cat.i] != '\0')
		cat.i++;
	while (s2[cat.g] != '\0')
		ft_for_strcat(&cat, s1, s2, inf);
	s1[cat.i] = '\0';
	return (s1);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
