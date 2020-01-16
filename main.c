/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:24:40 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/16 15:36:46 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"
#define DBL_INF		0x7FF0000000000000
#define DBL_NINF	0xFFF0000000000000
#define DBL_NAN		0x7FF0000000100000
#define DBL_PZERO	0x0000000000000000
#define DBL_NZERO	0x8000000000000000
#define LDBL_INF	0x7FFF0000000000000000L
#define LDBL_NINF	0xFFFF0000000000000000L
#define LDBL_NAN	0x7FFF0000000001000000L
#define LDBL_PZERO	0x00000000000000000000L
#define LDBL_NZERO	0x80000000000000000000L

int	main(void)
{
	double special;

	*((unsigned long *)(&special)) = DBL_NZERO;
	printf("\nreturn %d\n", ft_printf("%x", -42));
	printf("\nreturn %d\n", printf("%x", -42));
	return (0);
}
