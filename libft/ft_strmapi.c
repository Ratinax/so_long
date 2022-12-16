/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:31:43 by tibernot          #+#    #+#             */
/*   Updated: 2022/11/11 14:02:05 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	sizestr;
	char			*s2;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	sizestr = ft_strlen(s);
	s2 = ft_strdup(s);
	if (!s2)
		return (NULL);
	while (i < sizestr)
	{
		s2[i] = f(i, s2[i]);
		i++;
	}
	return (s2);
}
