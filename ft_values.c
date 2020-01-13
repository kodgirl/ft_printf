/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_values.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:00:04 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/30 18:44:38 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	value_d(va_list list)
{
	int	value;

	value = va_arg(list, signed long long int);
	printf("\n VALUE %d", value);
	return (value);
}
