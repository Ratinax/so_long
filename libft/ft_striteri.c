/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:47:02 by tibernot          #+#    #+#             */
/*   Updated: 2022/11/10 13:24:42 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	sizes;
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	sizes = ft_strlen(s);
	while (i < sizes)
	{
		f(i, &s[i]);
		i++;
	}
}
