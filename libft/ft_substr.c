/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:00:28 by tibernot          #+#    #+#             */
/*   Updated: 2022/11/15 13:31:01 by tibernot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*newstr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	i = start;
	while (s[i] && i < len + start)
		i++;
	newstr = malloc(sizeof(char) * (i + 1 - start));
	if (!newstr)
		return (0);
	i = 0;
	while (s[i + start] && i < len)
	{
		newstr[i] = s[i + start];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
