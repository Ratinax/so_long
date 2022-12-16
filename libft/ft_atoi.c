/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:49:33 by tibernot          #+#    #+#             */
/*   Updated: 2022/12/08 14:53:44 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	s;
	long	tot;

	i = 0;
	s = 1;
	tot = 0;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		s *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (tot != ((tot * 10 + (s * (str[i] - '0'))) / 10))
			return ((int)((s + 1) / 2 / -1));
		tot = tot * 10 + s * (str[i] - '0');
		i++;
	}
	return ((int)tot);
}
