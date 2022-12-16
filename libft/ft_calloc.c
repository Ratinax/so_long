/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:15:36 by tibernot          #+#    #+#             */
/*   Updated: 2022/11/11 14:06:05 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pt;

	if (count > 0 && size > SIZE_MAX / count)
		return (NULL);
	pt = malloc(count * size);
	if (!pt)
		return (0);
	ft_bzero(pt, count * size);
	return (pt);
}
