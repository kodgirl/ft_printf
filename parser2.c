/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:56:29 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/14 17:57:06 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_csp(t_struct *inform, char sym)
{
	if (sym == 'c' || sym == '%')
	{
		inform->type = (sym == 'c') ? 'c' : '%';
		return (1);
	}
	else if (sym == 's' || sym == 'S')
	{
		inform->type = 's';
		return (1);
	}
	else if (sym == 'p')
	{
		inform->type = 'p';
		return (1);
	}
	else if (sym == 'f')
	{
		inform->type = 'f';
		return (1);
	}
	return (0);
}

int	ft_diouxx(t_struct *inform, char sym)
{
	if (sym == 'd' || sym == 'i')
	{
		inform->type = 'd';
		return (1);
	}
	else if (sym == 'u')
	{
		inform->type = 'u';
		return (1);
	}
	else if (sym == 'o')
	{
		inform->type = 'o';
		return (1);
	}
	else if (sym == 'x' || sym == 'X')
	{
		inform->type = (sym == 'X') ? 'X' : 'x';
		return (1);
	}
	else if (ft_csp(inform, sym))
		return (1);
	return (0);
}
