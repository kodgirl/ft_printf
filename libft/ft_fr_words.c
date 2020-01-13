/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fr_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:26:23 by nshelly           #+#    #+#             */
/*   Updated: 2019/09/01 22:04:59 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fr_words(char **str, size_t i)
{
	if (!str)
		return ;
	while (i--)
		ft_strdel(&(str[i]));
	free(*str);
}
