/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:09:49 by tibernot          #+#    #+#             */
/*   Updated: 2022/11/10 18:23:17 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n - 1 && ((unsigned char *)s)[i] != (unsigned char)c)
		i++;
	if (((unsigned char *)s)[i] == (unsigned char)c)
		return (((void *)s) + i);
	return (0);
}
