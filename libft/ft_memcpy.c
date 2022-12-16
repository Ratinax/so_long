/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:12:10 by tibernot          #+#    #+#             */
/*   Updated: 2022/11/11 13:40:43 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pt;

	if (!dst && !src)
		return (NULL);
	pt = dst;
	while (n--)
		pt[n] = ((unsigned char *)src)[n];
	return (dst);
}
