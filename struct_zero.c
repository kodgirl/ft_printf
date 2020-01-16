/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:19:58 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/16 15:02:05 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	struct_zero(t_struct *inf)
{
	inf->minus = 0;
	inf->plus = 0;
	inf->space = 0;
	inf->sharp = 0;
	inf->zero = 0;
	inf->type = '\0';
	inf->width = 0;
	inf->precision = 0;
	inf->stopflags = 0;
	inf->h = 0;
	inf->hh = 0;
	inf->l = 0;
	inf->ll = 0;
}
