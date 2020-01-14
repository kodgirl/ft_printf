/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:19:58 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/14 18:25:27 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	struct_zero(t_struct *inform)
{
	inform->minus = 0;
	inform->plus = 0;
	inform->space = 0;
	inform->sharp = 0;
	inform->zero = 0;
	inform->type = '\0';
	inform->width = 0;
	inform->precision = 0;
	inform->stopflags = 0;
	inform->h = 0;
	inform->hh = 0;
	inform->l = 0;
	inform->ll = 0;
}
