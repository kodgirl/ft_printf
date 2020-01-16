/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:56:29 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/16 15:02:05 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_csp(t_struct *inf, char sym)
{
	if (sym == 'c' || sym == '%')
	{
		inf->type = (sym == 'c') ? 'c' : '%';
		return (1);
	}
	else if (sym == 's' || sym == 'S')
	{
		inf->type = 's';
		return (1);
	}
	else if (sym == 'p')
	{
		inf->type = 'p';
		return (1);
	}
	else if (sym == 'f')
	{
		inf->type = 'f';
		return (1);
	}
	return (0);
}

int	ft_diouxx(t_struct *inf, char sym)
{
	if (sym == 'd' || sym == 'i')
	{
		inf->type = 'd';
		return (1);
	}
	else if (sym == 'u')
	{
		inf->type = 'u';
		return (1);
	}
	else if (sym == 'o')
	{
		inf->type = 'o';
		return (1);
	}
	else if (sym == 'x' || sym == 'X')
	{
		inf->type = (sym == 'X') ? 'X' : 'x';
		return (1);
	}
	else if (ft_csp(inf, sym))
		return (1);
	return (0);
}
