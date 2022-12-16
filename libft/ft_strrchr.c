/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:53:45 by tibernot          #+#    #+#             */
/*   Updated: 2022/11/10 18:26:40 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*pt;

	pt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			pt = (((char *)s) + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
			pt = (((char *)s) + i);
	return (pt);
}
