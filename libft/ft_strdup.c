/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:49:06 by tibernot          #+#    #+#             */
/*   Updated: 2022/12/12 13:37:02 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pt;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	pt = malloc(sizeof(char) * (i + 1));
	if (!(pt))
		return (0);
	i = 0;
	while (s1[i])
	{
		pt[i] = ((char *)s1)[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
