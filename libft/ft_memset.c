/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:42:54 by tibernot          #+#    #+#             */
/*   Updated: 2022/11/09 08:56:53 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pt;
	size_t			i;

	pt = b;
	i = 0;
	while (i < len)
	{
		pt[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
