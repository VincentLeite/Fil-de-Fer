/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:09 by vleite            #+#    #+#             */
/*   Updated: 2015/11/27 12:35:49 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *str, size_t n)
{
	size_t i;

	i = 0;
	while (str[i] != '\0' && i < n)
	{
		dst[i] = str[i];
		i = i + 1;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i = i + 1;
	}
	return (dst);
}
