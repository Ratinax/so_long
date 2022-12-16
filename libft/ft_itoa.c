/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:52:24 by tibernot          #+#    #+#             */
/*   Updated: 2022/11/10 09:30:49 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size_s(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		if (n == -2147483648)
			return (11);
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	fill_str(char *str, long int n, int sizestr)
{
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 9)
	{
		str[sizestr - 1] = (n % 10 + '0');
		n /= 10;
		sizestr--;
	}
	str[sizestr - 1] = (n % 10 + '0');
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sizestr;

	sizestr = size_s(n);
	str = malloc((sizestr + 1) * sizeof(char));
	if (!str)
		return (NULL);
	fill_str(str, (long int)n, sizestr);
	str[sizestr] = '\0';
	return (str);
}
