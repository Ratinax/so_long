/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:43:41 by tibernot          #+#    #+#             */
/*   Updated: 2022/12/12 13:37:34 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pt;
	size_t			i;

	pt = dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst < src && src < dst + len)
	{
		while (i < len)
		{
			pt[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (len--)
			pt[len] = ((unsigned char *)src)[len];
	}
	return (dst);
}
