/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:22:51 by tibernot          #+#    #+#             */
/*   Updated: 2022/11/15 11:25:50 by tibernot         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	n2;
	long int	div;

	n2 = (long int)n;
	div = 1;
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n == 0)
		return ;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n2 *= -1;
	}
	while (n2 / div > 9)
		div *= 10;
	while (div > 9)
	{
		ft_putchar_fd(n2 / div + '0', fd);
		n2 -= (n2 / div) * div;
		div /= 10;
	}
	ft_putchar_fd(n2 / div + '0', fd);
}
