/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:13:29 by tibernot          #+#    #+#             */
/*   Updated: 2022/11/12 13:11:21 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	size_dst;

	if ((!dst || !src) && !dstsize)
		return (0);
	i = ft_strlen(dst);
	size_dst = i;
	j = 0;
	if (ft_strlen(dst) + 1 > dstsize)
		return (ft_strlen(src) + dstsize);
	while (i < dstsize - 1 && j < ft_strlen(src))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (size_dst + ft_strlen(src));
}
